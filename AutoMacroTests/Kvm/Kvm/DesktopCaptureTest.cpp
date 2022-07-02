#pragma once
#include "AutoMacro/Kvm/Kvm.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace KvmTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

TEST_CLASS(DesktopCaptureTest) {
public:
TEST_METHOD(TestImageIsValid) {
    auto videoCapture = Factory::createDesktopCapture();
    Image image = videoCapture->takeSnapshot();
    Assert::AreNotEqual(0, image.width());
    Assert::AreNotEqual(0, image.height());
    Assert::IsTrue(image.data() != nullptr);
}
};
}  // namespace KvmTest
}  // namespace AutoMacro
