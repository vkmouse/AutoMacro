#include "AutoMacro/Cv/Cv.h"
#include "AutoMacroTests/Cv/AssertExtension.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace ImageProcessorTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

TEST_CLASS(BGRConverterProcessorTest) {
public:
TEST_METHOD(TestBGRConverterProcessor) {
    Image expected =
        Cv::imread("images\\AutoMacroTests\\ItemExists_10x10_24bits.png");
    Image acutal =
        Cv::imread("images\\AutoMacroTests\\ItemExists_10x10_32bits.png");
    auto processor = Factory::createBGRConverterProcessor();
    acutal = processor->process(acutal);
    Assert::AreEqual(expected, acutal);
}
};
}  // namespace ImageProcessorTest
}  // namespace AutoMacro
