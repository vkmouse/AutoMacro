#include "AutoMacroTest/Core/ImageTest.h"

#include "CppUnitTest.h"
#include <AutoMacro/Core/Core.h>

namespace AutoMacro {
namespace {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

void assertArrayAreEqual(
    int size,
    unsigned char* expected,
    unsigned char* actual) {
    for (int i = 0; i < size; i++) {
        Assert::AreEqual(expected[i], actual[i]);
    }
}

void assertImageIsCorrect(
    const Image& image,
    int width,
    int height,
    int channel,
    unsigned char* data) {
    Assert::AreEqual(width, image.width());
    Assert::AreEqual(height, image.height());
    Assert::AreEqual(channel, image.channel());
    assertArrayAreEqual(width * height * channel, data, image.data());
}
}  // namespace

void ImageTest::TestImage() {
    int width = 1;
    int height = 3;
    int channel = 3;
    unsigned char data[9] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };

    Image image(width, height, channel, data);
    Image other(width, height, channel, data);

    assertImageIsCorrect(image, width, height, channel, data);
    assertImageIsCorrect(other, width, height, channel, data);

    Assert::IsTrue(image == other);
}
}  // namespace AutoMacro
