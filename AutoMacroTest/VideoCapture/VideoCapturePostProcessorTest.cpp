#include "AutoMacroTest/VideoCapture/VideoCapturePostProcessorTest.h"

#include "CppUnitTest.h"

#include <AutoMacro/ImageProcessor/ImageProcessor.h>
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
    ImageProcessor* processor = Factory::createBGRConverterProcessor();
    videoCapture = Factory::addVideoCapturePostprocessing(
        videoCapture, processor);
    for (int i = 0; i < 2; i++) {
        Image image = videoCapture->takeSnapshot();
        Assert::AreEqual(3, image.channel());
    }
    delete(videoCapture);
    delete(processor);
}

void VideoCapturePostProcessorTest::TestCroppingProcessor() {
    VideoCapture* videoCapture = Factory::createImageFileCapture({
        "images\\AutoMacroTest\\Template_5x5_24bits.png",
        "images\\AutoMacroTest\\Sample_10x10_32bits.png",
    });
    ImageProcessor* processor = Factory::createCroppingProcessor(0, 0, 5, 5);
    videoCapture = Factory::addVideoCapturePostprocessing(
        videoCapture, processor);
    for (int i = 0; i < 2; i++) {
        Image image = videoCapture->takeSnapshot();
        Assert::AreEqual(5, image.width());
        Assert::AreEqual(5, image.height());
    }
    delete(videoCapture);
    delete(processor);
}

void VideoCapturePostProcessorTest::TestMixedProcessor() {
    VideoCapture* videoCapture = Factory::createImageFileCapture({
        "images\\AutoMacroTest\\Template_5x5_24bits.png",
        "images\\AutoMacroTest\\Sample_10x10_32bits.png",
    });
    ImageProcessor* processor1 = Factory::createBGRConverterProcessor();
    ImageProcessor* processor2 = Factory::createCroppingProcessor(0, 0, 5, 5);
    videoCapture = Factory::addVideoCapturePostprocessing(
        videoCapture, processor1);
    videoCapture = Factory::addVideoCapturePostprocessing(
        videoCapture, processor2);
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
    videoCapture = Factory::addVideoCapturePostprocessing(
        videoCapture, processor2);
    videoCapture = Factory::addVideoCapturePostprocessing(
        videoCapture, processor1);
    for (int i = 0; i < 2; i++) {
        Image image = videoCapture->takeSnapshot();
        Assert::AreEqual(5, image.width());
        Assert::AreEqual(5, image.height());
        Assert::AreEqual(3, image.channel());
    }
    delete(videoCapture);
    delete(processor1);
    delete(processor2);
}
}  // namespace AutoMacro
