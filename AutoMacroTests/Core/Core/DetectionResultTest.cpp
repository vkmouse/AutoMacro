#include "AutoMacro/Core/Core.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace CoreTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

TEST_CLASS(DetectionResultTest) {
public:
TEST_METHOD(TestDetectionResult) {
    Rect region(2, 3, 4, 5);
    int index = 5;
    float confidence = 0.5f;
    DetectionResult result(
        index,
        region.x,
        region.y,
        region.width,
        region.height,
        confidence);

    Assert::IsTrue(region == result.region());
    Assert::IsTrue(region.center() == result.center());
    Assert::AreEqual(index, result.index);
    Assert::AreEqual(confidence, result.confidence);
}
};
}  // namespace CoreTest
}  // namespace AutoMacro
