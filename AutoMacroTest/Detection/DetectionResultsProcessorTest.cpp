#include "AutoMacroTest/Detection/DetectionResultsProcessorTest.h"

#include "CppUnitTest.h"

#include <AutoMacro/Detection/Detection.h>

namespace AutoMacro {
namespace Detection {
namespace {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;
}  // namesapce

void DetectionResultsProcessorTest::TestItemExists() {
    DetectionResult result1;
    result1.index = 1;
    result1.confidence = 0.9f;

    DetectionResult result2;
    result2.index = 2;
    result2.confidence = 0.5f;

    DetectionResults results;
    results.push_back(result1);
    results.push_back(result2);

    Assert::IsTrue(results.exists(0.8f));
    Assert::IsFalse(results.exists(0.95f));
    Assert::IsTrue(results.exists(1, 0.8f));
    Assert::IsFalse(results.exists(2, 0.8f));
}
}  // namespace Detection
}  // namespace AutoMacro
