#include "AutoMacro/Kvm/Kvm/HIDMouse.h"

#include <Windows.h>
#include <stdexcept>
#include <vector>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Kvm/Kvm/KbdMouDevice.h"

namespace AutoMacro {
namespace Impl {
namespace {
int getVirtualKey(MouseButton button) {
    switch (button) {
    case MouseButton::BUTTON_NONE: return 0;
    case MouseButton::BUTTON_LEFT: return VK_LBUTTON;
    case MouseButton::BUTTON_RIGHT: return VK_RBUTTON;
    case MouseButton::BUTTON_MIDDLE: return VK_MBUTTON;
    default: return 0;
    }
}

class MouseSpeedMatcher {
 public:
    MouseSpeedMatcher() {
        maxDistance = getDistanceBySpeed(CHAR_MAX);
        speedByDistance.resize(maxDistance + 1);

        for (int speed = 0, distance = 0; speed < CHAR_MAX + 1; speed++) {
            int distanceOfCurrSpeed = getDistanceBySpeed(speed);
            for (; distance < distanceOfCurrSpeed + 1; distance++) {
                speedByDistance[distance] = static_cast<CHAR>(speed);
            }
        }
    }

    CHAR getSpeed(int distance) {
        if (distance >= 0) {
            return getSpeedByPositiveDistance(distance);
        } else {
            return getSpeedByNegativeDistance(distance);
        }
    }

 private:
    static int getDistanceBySpeed(int speed) {
        int sensitivity = getMouseSensivity();
        int eppSpeed = getMouseSpeed();
        double distance = calcMouseSpeedFactor(sensitivity, eppSpeed) * (speed);
        return static_cast<int>(distance);
    }

    static int getMouseSensivity() {
        DWORD size = 3;
        char buffer[3];

        LONG getValueResult = RegGetValueA(
            HKEY_CURRENT_USER,
            "Control Panel\\Mouse",
            "MouseSensitivity",
            RRF_RT_REG_SZ,
            nullptr,
            &buffer,
            &size);
        if (ERROR_SUCCESS != getValueResult) {
            return -1;
        }

        return atoi(buffer);
    }

    static int getMouseSpeed() {
        DWORD size = 2;
        char buffer[2];

        LONG getValueResult = RegGetValueA(
            HKEY_CURRENT_USER,
            "Control Panel\\Mouse",
            "MouseSpeed",
            RRF_RT_REG_SZ,
            nullptr,
            &buffer,
            &size);
        if (ERROR_SUCCESS != getValueResult) {
            return -1;
        }

        return atoi(buffer);
    }

    static double calcMouseSpeedFactor(int sensitivity, int eppSpeed) {
        double sensitivityFactors[21] = { 0,     0.03125, 0.0625, 0.125, 0.25,
                                          0.375, 0.5,     0.625,  0.75,  0.875,
                                          1,     1.25,    1.5,    1.75,  2,
                                          2.25,  2.5,     2.75,   3,     3.25,
                                          3.5 };

        if (sensitivity < SENSITIVITY_MIN || sensitivity > SENSITIVITY_MAX ||
            eppSpeed < EPP_DISABLED || eppSpeed > EPP_ENABLED) {
            return 1.0;
        } else if (eppSpeed == EPP_ENABLED) {
            return 0.25 * sensitivity;
        } else {
            return sensitivityFactors[sensitivity];
        }
    }

    static const int EPP_DISABLED = 0;
    static const int EPP_ENABLED = 1;
    static const int SENSITIVITY_MIN = 1;
    static const int SENSITIVITY_MAX = 20;

    CHAR getSpeedByPositiveDistance(int distance) const {
        if (distance > maxDistance) {
            return speedByDistance[maxDistance];
        } else {
            return speedByDistance[distance];
        }
    }

    CHAR getSpeedByNegativeDistance(int distance) const {
        if (distance < -maxDistance) {
            return -speedByDistance[maxDistance];
        } else {
            return -speedByDistance[-distance];
        }
    }

    std::vector<CHAR> speedByDistance;
    int maxDistance;
};
}  // namespace

class HIDMouse::Impl : public KbdMouDevice {
 public:
    explicit Impl(const HIDMouse& mouse) :
        KbdMouDevice(L"\\\\?\\HID#VARIABLE_6&Col02#1"),
        mouse(mouse) {
    }

    void mouseDown(MouseButton button) {
        buttons |= (BYTE)button;
        sendMouseReport();
    }

    void mouseUp(MouseButton button) {
        buttons &= ~(BYTE)button;
        sendMouseReport();
    }

    void mouseMove(int x, int y) {
        Point destination = { x, y };
        Point current = mouse.getCurrentPosition();
        while (!lessThanTolerance(current, destination)) {
            CHAR xSpeed = speedMatcher.getSpeed(destination.x - current.x);
            CHAR ySpeed = speedMatcher.getSpeed(destination.y - current.y);
            sendMouseReport(xSpeed, ySpeed);
            current = mouse.getCurrentPosition();
        }
    }

    void releaseAllButtons() {
        buttons = 0x00;
        sendMouseReport();
    }

 private:
    struct Report {
        BYTE reportId;
        BYTE buttons;
        CHAR x;
        CHAR y;
    };

    static const BYTE REPORT_ID = 0x02;
    static const int DISTANCE_TOLERANCE = 3;

    static bool lessThanTolerance(Point point1, Point point2) {
        return calcDistance(point1, point2) <= DISTANCE_TOLERANCE;
    }

    static double calcDistance(Point point1, Point point2) {
        double deltaX = static_cast<double>(point1.x) - point2.x;
        double deltaY = static_cast<double>(point1.y) - point2.y;
        return sqrt(pow(deltaX, 2) + pow(deltaY, 2));
    }

    void sendMouseReport(CHAR xSpeed = 0, CHAR ySpeed = 0) {
        Report report;
        report.reportId = REPORT_ID;
        report.buttons = buttons;
        report.x = xSpeed;
        report.y = ySpeed;

        setOutputReport(&report, static_cast<DWORD>(sizeof(Report)));
    }

    BYTE buttons = 0x00;
    MouseSpeedMatcher speedMatcher;
    const HIDMouse& mouse;
};

HIDMouse::HIDMouse() : impl(new Impl(*this)) {
    impl->initialize();
}

HIDMouse::~HIDMouse() {
}

Point HIDMouse::getCurrentPosition() const {
    POINT point;
    BOOL success = GetCursorPos(&point);
    if (!success) {
        throw std::runtime_error{ "GET_CURRENT_POSITION_ERROR" };
    }
    return { point.x, point.y };
}

bool HIDMouse::isMouseButtonDown(MouseButton button) const {
    int virtualKey = getVirtualKey(button);
    return GetKeyState(virtualKey) & 0x80;
}

void HIDMouse::mouseDown(MouseButton button) {
    impl->mouseDown(button);
}

void HIDMouse::mouseUp(MouseButton button) {
    impl->mouseUp(button);
}

void HIDMouse::mouseMove(int x, int y) {
    impl->mouseMove(x, y);
}

void HIDMouse::releaseAllButtons() {
    impl->releaseAllButtons();
}
}  // namespace Impl
}  // namespace AutoMacro
