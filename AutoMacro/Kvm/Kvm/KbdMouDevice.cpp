#include "AutoMacro/Kvm/Kvm/KbdMouDevice.h"

#include <cfgmgr32.h>
#include <hidsdi.h>
#include <chrono>
#include <stdexcept>

namespace AutoMacro {
namespace Impl {
KbdMouDevice::KbdMouDevice(PCWSTR deviceInterface) :
    mp_deviceInterface(deviceInterface) {
}

void KbdMouDevice::initialize() {
    if (isInitialized()) {
        throw std::runtime_error{ "ERROR_DOUBLE_INITIALIZATION" };
    }

    GUID guid;
    HidD_GetHidGuid(&guid);

    ULONG deviceInterfaceListLength = 0;
    CONFIGRET configret = CM_Get_Device_Interface_List_Size(
        &deviceInterfaceListLength,
        &guid,
        nullptr,
        CM_GET_DEVICE_INTERFACE_LIST_PRESENT);
    if (CR_SUCCESS != configret) {
        throw std::runtime_error{ "ERROR_GETTING_DEVICE_INTERFACE_LIST_SIZE" };
    }

    if (deviceInterfaceListLength <= 1) {
        throw std::runtime_error{ "ERROR_EMPTY_DEVICE_INTERFACE_LIST" };
    }

    PWSTR deviceInterfaceList = static_cast<PWSTR>(
        malloc(deviceInterfaceListLength * sizeof(WCHAR)));
    if (nullptr == deviceInterfaceList) {
        throw std::runtime_error{ "ERROR_ALLOCATING_DEVICE_INTERFACE_LIST" };
    }
    ZeroMemory(deviceInterfaceList, deviceInterfaceListLength * sizeof(WCHAR));

    configret = CM_Get_Device_Interface_List(
        &guid,
        nullptr,
        deviceInterfaceList,
        deviceInterfaceListLength,
        CM_GET_DEVICE_INTERFACE_LIST_PRESENT);
    if (CR_SUCCESS != configret) {
        free(deviceInterfaceList);
        throw std::runtime_error{ "ERROR_GETTING_DEVICE_INTERFACE_LIST" };
    }

    size_t deviceInterfaceLength = wcslen(mp_deviceInterface);
    HANDLE file = INVALID_HANDLE_VALUE;
    for (PWSTR currentInterface = deviceInterfaceList;
         *currentInterface;
         currentInterface += wcslen(currentInterface) + 1) {
        if (0 != wcsncmp(currentInterface,
                         mp_deviceInterface,
                         deviceInterfaceLength)) {
            continue;
        }

        file = CreateFile(currentInterface,
                          GENERIC_WRITE,
                          FILE_SHARE_WRITE,
                          nullptr,
                          OPEN_EXISTING,
                          0,
                          nullptr);
        if (INVALID_HANDLE_VALUE == file) {
            continue;
        }

        break;
    }
    free(deviceInterfaceList);
    if (INVALID_HANDLE_VALUE == file) {
        throw std::runtime_error{ "ERROR_INVALID_HANDLE_VALUE" };
    }

    mp_deviceHandle = file;
    m_isInitialized = true;
}

bool KbdMouDevice::isInitialized() const {
    return m_isInitialized;
}

bool KbdMouDevice::isAborted() const {
    return m_isAborted;
}

void KbdMouDevice::abort() {
    if (nullptr != mp_deviceHandle && INVALID_HANDLE_VALUE != mp_deviceHandle) {
        CloseHandle(mp_deviceHandle);
    }
    m_isAborted = true;
}

void KbdMouDevice::setOutputReport(PVOID data, DWORD size) {
    using std::chrono::high_resolution_clock;
    auto start = high_resolution_clock::now();

    if (!HidD_SetOutputReport(mp_deviceHandle, data, size)) {
        throw std::runtime_error{ "ERROR_SET_OUTPUT_REPORT" };
    }

    auto duration = high_resolution_clock::now() - start;
    auto timeout = std::chrono::milliseconds(1);
    while (duration < timeout) {
        duration = high_resolution_clock::now() - start;
    }
}
}  // namespace Impl
}  // namespace AutoMacro
