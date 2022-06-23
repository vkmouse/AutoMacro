#include "AutoMacroTest/VideoCapture/DesktopCaptureTest.h"

#include <Windows.h>
#include <string>

#include "CppUnitTest.h"
#include <AutoMacro/Cv/Cv.h>
#include <AutoMacro/ImageProcessor/ImageProcessor.h>
#include <AutoMacro/VideoCapture/VideoCapture.h>
#include "AutoMacroTest/Assert/AssertExtension.h"

namespace AutoMacro {
namespace {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;
}  // namespace
void DesktopCaptureTest::TestTakeSnapshotWithProcessor() {
    std::string filename = "images\\AutoMacroTest\\Template_5x5_24bits.png";
    Image expected = Cv::imread(filename);

    auto videoCapture = Factory::createDesktopCapture();
    Image image = videoCapture->takeSnapshot();
    Rect region(
        (1920 / 2) - (expected.width() / 2),
        (1080 / 2) - (expected.height() / 2),
        expected.width(),
        expected.height());
    if (image.width() > 1920) {
        region.x = region.x + image.width() - 1920;
    }
    auto croppingProcessor = Factory::createCroppingProcessor(region);
    auto converterProcessor = Factory::createBGRConverterProcessor();
    videoCapture = Factory::addPostprocessing(videoCapture, croppingProcessor);
    videoCapture = Factory::addPostprocessing(videoCapture, converterProcessor);

    system(filename.c_str());
    Sleep(400);
    Image actual = videoCapture->takeSnapshot();
        
    Assert::AreEqual(expected, actual);
    system("TASKKILL /F /IM Microsoft.Photos.exe");
}

void DesktopCaptureTest::TestImageIsValid() {
    auto videoCapture = Factory::createDesktopCapture();
    Image image = videoCapture->takeSnapshot();
    Assert::AreNotEqual(0, image.width());
    Assert::AreNotEqual(0, image.height());
    Assert::IsTrue(image.data() != nullptr);
}
}  // namespace AutoMacro
