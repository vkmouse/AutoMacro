#include "AutoMacroTest/ImageProcessor/BGRConverterProcessorTest.h"

#include <memory>

#include "CppUnitTest.h"
#include <AutoMacro/Cv/Cv.h>
#include <AutoMacro/ImageProcessor/ImageProcessor.h>
#include "AutoMacroTest/Assert/AssertExtension.h"

namespace AutoMacro {
namespace {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;
}  // namespace

void BGRConverterProcessorTest::TestBGRConverterProcessor() {
    Image expected = Cv::imread("images\\AutoMacroTest\\ItemExists_10x10_24bits.png");
    Image acutal = Cv::imread("images\\AutoMacroTest\\ItemExists_10x10_32bits.png");
    auto processor = Factory::createBGRConverterProcessor();
    acutal = processor->process(acutal);
    Assert::AreEqual(expected, acutal);
}
}  // namespace AutoMacro
