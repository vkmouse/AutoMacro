#include "AutoMacro/VideoCapture/VideoCapture/DesktopCapture.h"

#include <Windows.h>

namespace AutoMacro {
namespace Impl {
class DesktopCapture::Impl {
 public:
    Impl() {
        hWnd = GetDesktopWindow();
        data = new unsigned char[width() * height() * 4];
    }

    int width() const {
        return GetSystemMetrics(SM_CXVIRTUALSCREEN);
    }

    int height() const {
        return GetSystemMetrics(SM_CYVIRTUALSCREEN);
    }

    unsigned char* takeSnapshot() {
        // get handles to a device context (DC)
        HDC hwindowDC = GetDC(hWnd);
        HDC hwindowCompatibleDC = CreateCompatibleDC(hwindowDC);
        SetStretchBltMode(hwindowCompatibleDC, COLORONCOLOR);

        // define scale, height and width
        int screenx = GetSystemMetrics(SM_XVIRTUALSCREEN);
        int screeny = GetSystemMetrics(SM_YVIRTUALSCREEN);

        // create a bitmap
        HBITMAP hbwindow = CreateCompatibleBitmap(hwindowDC, width(), height());
        BITMAPINFOHEADER bi = createBitmapHeader();

        // use the previously created device context with the bitmap
        SelectObject(hwindowCompatibleDC, hbwindow);

        // copy from the window device context to the bitmap device context
        StretchBlt(
            hwindowCompatibleDC,
            0, 0, width(), height(),
            hwindowDC,
            screenx, screeny, width(), height(),
            SRCCOPY);
        GetDIBits(hwindowCompatibleDC,
            hbwindow,
            0, height(),
            data,
            reinterpret_cast<BITMAPINFO*>(&bi),
            DIB_RGB_COLORS);

        // avoid memory leak
        DeleteObject(hbwindow);
        DeleteDC(hwindowCompatibleDC);
        ReleaseDC(hWnd, hwindowDC);

        return data;
    }

 private:
    BITMAPINFOHEADER createBitmapHeader() {
        BITMAPINFOHEADER  bi;

        // create a bitmap
        bi.biSize = sizeof(BITMAPINFOHEADER);
        bi.biWidth = width();
        bi.biHeight = -height();
        bi.biPlanes = 1;
        bi.biBitCount = 32;
        bi.biCompression = BI_RGB;
        bi.biSizeImage = 0;
        bi.biXPelsPerMeter = 0;
        bi.biYPelsPerMeter = 0;
        bi.biClrUsed = 0;
        bi.biClrImportant = 0;

        return bi;
    }

    HWND hWnd;
    unsigned char* data;
};

DesktopCapture::DesktopCapture() :
    impl(new Impl) {
}

Image DesktopCapture::takeSnapshot() {
    int width = impl->width();
    int height = impl->height();
    unsigned char* data = impl->takeSnapshot();
    Image image(width, height, 4, data);
    return image;
}
}  // namespace Impl
}  // namespace AutoMacro
