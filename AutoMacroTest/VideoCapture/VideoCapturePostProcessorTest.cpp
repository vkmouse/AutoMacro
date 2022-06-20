#include "AutoMacroTest/VideoCapture/VideoCapturePostProcessorTest.h"

#include <memory>

#include "CppUnitTest.h"
#include <AutoMacro/ImageProcessor/ImageProcessor.h>
#include <AutoMacro/VideoCapture/VideoCapture.h>

namespace AutoMacro {
namespace {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;
}  // namespace

void VideoCapturePostProcessorTest::TestBGRConverterProcessor() {
    auto videoCapture = Factory::createImageFileCapture({
        "images\\AutoMacroTest\\Template_5x5_24bits.png",
        "images\\AutoMacroTest\\Sample_10x10_32bits.png",
    });
    auto processor = Factory::createBGRConverterProcessor();
    videoCapture = Factory::addPostprocessing(videoCapture, processor);
    for (int i = 0; i < 2; i++) {
        Image image = videoCapture->takeSnapshot();
        Assert::AreEqual(3, image.channel());
    }
}

void VideoCapturePostProcessorTest::TestCroppingProcessor() {
    auto videoCapture = Factory::createImageFileCapture({
        "images\\AutoMacroTest\\Template_5x5_24bits.png",
        "images\\AutoMacroTest\\Sample_10x10_32bits.png",
    });
    auto processor = Factory::createCroppingProcessor(0, 0, 5, 5);
    videoCapture = Factory::addPostprocessing(videoCapture, processor);
    for (int i = 0; i < 2; i++) {
        Image image = videoCapture->takeSnapshot();
        Assert::AreEqual(5, image.width());
        Assert::AreEqual(5, image.height());
    }
}

void VideoCapturePostProcessorTest::TestMixedProcessor() {
    auto videoCapture = Factory::createImageFileCapture({
        "images\\AutoMacroTest\\Template_5x5_24bits.png",
        "images\\AutoMacroTest\\Sample_10x10_32bits.png",
    });
    auto processor1 = Factory::createBGRConverterProcessor();
    auto processor2 = Factory::createCroppingProcessor(0, 0, 5, 5);
    videoCapture = Factory::addPostprocessing(videoCapture, processor1);
    videoCapture = Factory::addPostprocessing(videoCapture, processor2);
    for (int i = 0; i < 2; i++) {
        Image image = videoCapture->takeSnapshot();
        Assert::AreEqual(5, image.width());
        Assert::AreEqual(5, image.height());
        Assert::AreEqual(3, image.channel());
    }

    videoCapture = Factory::createImageFileCapture({
        "images\\AutoMacroTest\\Template_5x5_24bits.png",
        "images\\AutoMacroTest\\Sample_10x10_32bits.png",
    });
    videoCapture = Factory::addPostprocessing(
        videoCapture, processor2);
    videoCapture = Factory::addPostprocessing(
        videoCapture, processor1);
    for (int i = 0; i < 2; i++) {
        Image image = videoCapture->takeSnapshot();
        Assert::AreEqual(5, image.width());
        Assert::AreEqual(5, image.height());
        Assert::AreEqual(3, image.channel());
    }
}
}  // namespace AutoMacro
