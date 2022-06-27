#include "AutoMacroTest/ImageProcessor/CroppingProcessorTest.h"

#include <memory>

#include "AutoMacro/Cv/Cv.h"
#include "AutoMacro/ImageProcessor/ImageProcessor.h"
#include "AutoMacroTest/Assert/AssertExtension.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;
}  // namespace

void CroppingProcessorTest::TestCroppingProcessor() {
    Image expected =
        Cv::imread("images\\AutoMacroTest\\Template_5x5_24bits.png");
    Image acutal =
        Cv::imread("images\\AutoMacroTest\\ItemExists_10x10_24bits.png");
    auto processor = Factory::createCroppingProcessor(3, 1, 5, 5);
    acutal = processor->process(acutal);
    Assert::AreEqual(expected, acutal);
}
}  // namespace AutoMacro
