#include "AutoMacroTest/VideoCapture/ImageFileCaptureTest.h"

#include "CppUnitTest.h"
#include <AutoMacro/VideoCapture/VideoCapture.h>
#include <AutoMacro/VideoCapture/ImageFileCapture.h>

namespace AutoMacro {
namespace {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;
}  // namespace

void ImageFileCaptureTest::TestTakeSnapshot() {
    VideoCapture* videoCapture = Factory::createImageFileCapture({
        "images\\AutoMacroTest\\Template_5x5_24bits.png",
        "images\\AutoMacroTest\\Sample_10x10_32bits.png",
    });
    Image image = videoCapture->takeSnapshot();
    Assert::AreEqual(5, image.width());
    Assert::AreEqual(5, image.height());
    Assert::AreEqual(3, image.channel());
    Assert::IsNotNull(image.data());

    image = videoCapture->takeSnapshot();
    Assert::AreEqual(10, image.width());
    Assert::AreEqual(10, image.height());
    Assert::AreEqual(4, image.channel());
    Assert::IsNotNull(image.data());
    delete(videoCapture);
}

void ImageFileCaptureTest::TestCycleImages() {
    VideoCapture* videoCapture = Factory::createImageFileCapture({
        "images\\AutoMacroTest\\Template_5x5_24bits.png",
        "images\\AutoMacroTest\\ItemExists_10x10_24bits.png"
    });
    int expected = 5;

    for (int i = 0; i < 10; i++) {
        Image image = videoCapture->takeSnapshot();
        Assert::AreEqual(expected, image.width());
        Assert::AreEqual(expected, image.height());
        Assert::AreEqual(3, image.channel());
        Assert::IsNotNull(image.data());
        expected = expected == 5 ? 10 : 5;
    }

    delete(videoCapture);
}
}  // namespace AutoMacro
