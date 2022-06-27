#include "AutoMacroTest/Detection/DetectionResultTest.h"

#include "AutoMacro/Detection/Detection.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace Detection {
namespace {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;
}  // namesapce

void DetectionResultTest::TestDetectionResult() {
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

void DetectionResultTest::TestDetectionResults() {
    DetectionResults results;
    results.push_back(DetectionResult());
    Assert::AreEqual(static_cast<size_t>(1), results.size());

    results.clear();
    Assert::AreEqual(static_cast<size_t>(0), results.size());
}
}  // namespace Detection
}  // namespace AutoMacro
