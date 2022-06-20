#include "AutoMacroTest/ImageProcessor/CroppingProcessorTest.h"

#include <memory>

#include "CppUnitTest.h"
#include <AutoMacro/ImageProcessor/ImageProcessor.h>
#include <AutoMacro/VideoCapture/VideoCapture.h>

namespace AutoMacro {
namespace {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;
}  // namespace

void CroppingProcessorTest::TestCroppingProcessor() {
    auto videoCapture = Factory::createImageFileCapture({
        "images\\AutoMacroTest\\Template_5x5_24bits.png",
        "images\\AutoMacroTest\\Sample_10x10_32bits.png",
    });
    auto processor = Factory::createCroppingProcessor(0, 0, 5, 5);

    for (int i = 0; i < 2; i++) {
        Image image = videoCapture->takeSnapshot();
        image = processor->process(image);
        Assert::AreEqual(5, image.width());
        Assert::AreEqual(5, image.height());
    }
}
}  // namespace AutoMacro
