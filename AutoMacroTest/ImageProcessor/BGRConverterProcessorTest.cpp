#include "AutoMacroTest/ImageProcessor/BGRConverterProcessorTest.h"

#include "CppUnitTest.h"

#include <AutoMacro/ImageProcessor/ImageProcessor.h>
#include <AutoMacro/VideoCapture/VideoCapture.h>

namespace AutoMacro {
namespace {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;
}  // namespace

void BGRConverterProcessorTest::TestBGRConverterProcessor() {
    VideoCapture* videoCapture = Factory::createImageFileCapture({
        "images\\AutoMacroTest\\Template_5x5_24bits.png",
        "images\\AutoMacroTest\\Sample_10x10_32bits.png",
    });

    ImageProcessor* processor = Factory::createBGRConverterProcessor();
    for (int i = 0; i < 2; i++) {
        Image image = videoCapture->takeSnapshot();
        image = processor->process(image);
        Assert::AreEqual(3, image.channel());
    }

    delete(videoCapture);
}
}  // namespace AutoMacro