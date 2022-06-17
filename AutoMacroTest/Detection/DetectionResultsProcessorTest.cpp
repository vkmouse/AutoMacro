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

    DetectionResults results { result1, result2 };

    Assert::IsTrue(itemExists(results, 1, 0.8f));
    Assert::IsFalse(itemExists(results, 2, 0.8f));
}
}  // namespace Detection
}  // namespace AutoMacro
