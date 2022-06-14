#include "AutoMacroTest/VideoCapture/VideoCapturePostProcessorTest.h"

#include "CppUnitTest.h"

#include <AutoMacro/VideoCapture/BGRConverterProcessor.h>
#include <AutoMacro/VideoCapture/CroppingProcessor.h>
#include <AutoMacro/VideoCapture/VideoCapture.h>

namespace AutoMacro {
namespace {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;
}  // namespace

void VideoCapturePostProcessorTest::TestBGRConverterProcessor() {
    VideoCapture* videoCapture = Factory::createImageFileCapture({
        "images\\AutoMacroTest\\Template_5x5_24bits.png",
        "images\\AutoMacroTest\\Sample_10x10_32bits.png",
    });
    videoCapture = Factory::addBGRConverterProcessor(videoCapture);
    for (int i = 0; i < 2; i++) {
        Image image = videoCapture->takeSnapshot();
        Assert::AreEqual(3, image.channel());
    }
    delete(videoCapture);
}

void VideoCapturePostProcessorTest::TestCroppingProcessor() {
    VideoCapture* videoCapture = Factory::createImageFileCapture({
        "images\\AutoMacroTest\\Template_5x5_24bits.png",
        "images\\AutoMacroTest\\Sample_10x10_32bits.png",
    });
    videoCapture = Factory::addCroppingProcessor(videoCapture, 0, 0, 5, 5);
    for (int i = 0; i < 2; i++) {
        Image image = videoCapture->takeSnapshot();
        Assert::AreEqual(5, image.width());
        Assert::AreEqual(5, image.height());
    }
    delete(videoCapture);
}

void VideoCapturePostProcessorTest::TestMixedProcessor() {
    VideoCapture* videoCapture = Factory::createImageFileCapture({
        "images\\AutoMacroTest\\Template_5x5_24bits.png",
        "images\\AutoMacroTest\\Sample_10x10_32bits.png",
    });
    videoCapture = Factory::addBGRConverterProcessor(videoCapture);
    videoCapture = Factory::addCroppingProcessor(videoCapture, 0, 0, 5, 5);
    for (int i = 0; i < 2; i++) {
        Image image = videoCapture->takeSnapshot();
        Assert::AreEqual(5, image.width());
        Assert::AreEqual(5, image.height());
        Assert::AreEqual(3, image.channel());
    }
    delete(videoCapture);

    videoCapture = Factory::createImageFileCapture({
        "images\\AutoMacroTest\\Template_5x5_24bits.png",
        "images\\AutoMacroTest\\Sample_10x10_32bits.png",
    });
    videoCapture = Factory::addCroppingProcessor(videoCapture, 0, 0, 5, 5);
    videoCapture = Factory::addBGRConverterProcessor(videoCapture);
    for (int i = 0; i < 2; i++) {
        Image image = videoCapture->takeSnapshot();
        Assert::AreEqual(5, image.width());
        Assert::AreEqual(5, image.height());
        Assert::AreEqual(3, image.channel());
    }
    delete(videoCapture);
}
}  // namespace AutoMacro
