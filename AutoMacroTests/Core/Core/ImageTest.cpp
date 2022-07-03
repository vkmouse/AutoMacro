#include "AutoMacro/Core/Core.h"
#include "AutoMacroTests/AssertExtension.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace CoreTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

TEST_CLASS(ImageTest) {
public:
TEST_METHOD(TestImage) {
    int width = 1;
    int height = 3;
    int channel = 3;
    unsigned char data[9] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };

    Image image(width, height, channel, data);
    Image other(width, height, channel, data);

    Assert::AreEqual(image, other);
    Assert::IsTrue(image == other);
    Assert::IsFalse(image.data() == other.data());
}
};
}  // namespace CoreTest
}  // namespace AutoMacro
