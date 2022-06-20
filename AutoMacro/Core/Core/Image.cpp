#include <string.h>

#include "AutoMacro/Core/Core/Image.h"

namespace AutoMacro {
Image::Image(int width, int height, int channel, unsigned char* data) :
    width_(width),
    height_(height),
    channel_(channel) {
    copyFromData(data);
}

Image::Image(const Image& other) noexcept {
    width_ = other.width();
    height_ = other.height();
    channel_ = other.channel();
    copyFromData(other.data());
}

Image& Image::operator=(const Image& other) {
    width_ = other.width();
    height_ = other.height();
    channel_ = other.channel();
    copyFromData(other.data());
    return *this;
}

bool Image::operator==(const Image& other) const {
    bool areEqual = true;

    areEqual = areEqual && (width_ == other.width_);
    areEqual = areEqual && (height_ == other.height_);
    areEqual = areEqual && (channel_ == other.channel_);

    int size = width_ * height_ * channel_;
    for (int i = 0; i < size; i++) {
        areEqual = areEqual && (data_[i] == other.data_[i]);
    }

    return areEqual;
}

Image::~Image() {
    width_ = 0;
    height_ = 0;
    channel_ = 0;

    if (data_) {
        delete(data_);
        data_ = nullptr;
    }
}

int Image::width() const {
    return width_;
}

int Image::height() const {
    return height_;
}

int Image::channel() const {
    return channel_;
}

unsigned char* Image::data() const {
    return data_;
}

void Image::copyFromData(unsigned char* data) {
    int size = width_ * height_ * channel_;
    data_ = new unsigned char[size];
    memcpy(data_, data, size);
}
}  // namespace AutoMacro
