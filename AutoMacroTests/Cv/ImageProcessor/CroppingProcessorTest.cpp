#include "AutoMacro/Cv/Cv.h"
#include "AutoMacroTests/AssertExtension.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace ImageProcessorTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

TEST_CLASS(CroppingProcessorTest) {
public:
TEST_METHOD(TestCroppingProcessor) {
    Image expected =
        Cv::imread("images\\AutoMacroTests\\Template_5x5_24bits.png");
    Image acutal =
        Cv::imread("images\\AutoMacroTests\\ItemExists_10x10_24bits.png");
    auto processor = Factory::createCroppingProcessor(3, 1, 5, 5);
    acutal = processor->process(acutal);
    Assert::AreEqual(expected, acutal);
}
};
}  // namespace ImageProcessorTest
}  // namespace AutoMacro
