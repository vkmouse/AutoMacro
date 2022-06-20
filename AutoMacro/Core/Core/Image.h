#pragma once
#include "AutoMacro/Core/Core/pch.h"

namespace AutoMacro {
class DLL_EXPORTS Image {
 public:
    Image(int width, int height, int channel, unsigned char* data);
    Image(const Image& other) noexcept;

    Image& operator=(const Image& other);
    bool operator==(const Image& other) const;

    ~Image();

    int width() const;
    int height() const;
    int channel() const;
    unsigned char* data() const;

 private:
    void copyFromData(unsigned char* data);

    int width_;
    int height_;
    int channel_;
    unsigned char* data_;
};
}  // namespace AutoMacro
