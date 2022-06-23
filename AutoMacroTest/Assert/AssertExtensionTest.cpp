#include "AutoMacroTest/Assert/AssertExtensionTest.h"

#include <string>

#include "CppUnitTest.h"
#include <AutoMacro/Cv/Cv.h>
#include "AutoMacroTest/Assert/AssertExtension.h"

namespace AutoMacro {
namespace {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;
}  // namespace

void AssertExtensionTest::TestImageAreEqual() {
    std::string filename = "images\\AutoMacroTest\\Template_5x5_24bits.png";
    Image expected = Cv::imread(filename);
    Image actual = Cv::imread(filename);
    Assert::AreEqual(expected, expected);
    Assert::AreEqual(expected, actual);
    Assert::AreEqual(actual, actual);
}

void AssertExtensionTest::TestImageAreNotEqual() {
    Image lhs =
        Cv::imread("images\\AutoMacroTest\\Template_5x5_24bits.png");
    Image rhs =
        Cv::imread("images\\AutoMacroTest\\NotExistedTemplate_5x5_24bits.png");
    Assert::AreEqual(lhs, lhs);
    Assert::AreEqual(rhs, rhs);
    Assert::AreNotEqual(lhs, rhs);
}
}  // namespace AutoMacro
