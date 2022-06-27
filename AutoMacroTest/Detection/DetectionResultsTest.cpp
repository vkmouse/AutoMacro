#include "AutoMacroTest/Detection/DetectionResultsTest.h"

#include "AutoMacro/Detection/Detection.h"
#include "AutoMacroTest/Assert/AssertExtension.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace Detection {
namespace {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;
}  // namesapce

void DetectionResultsTest::TestExists() {
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
    Assert::IsTrue(results.exists(0.8f, 1));
    Assert::IsFalse(results.exists(0.8f, 2));
}

void DetectionResultsTest::TestCountAndWhere() {
    DetectionResult result1;
    result1.index = 1;
    result1.confidence = 0.9f;

    DetectionResult result2;
    result2.index = 2;
    result2.confidence = 0.5f;

    DetectionResult result3;
    result2.index = 3;
    result2.confidence = 0.9f;

    DetectionResults results;
    results.push_back(result1);
    results.push_back(result2);
    results.push_back(result3);

    Assert::AreEqual(2, results.count(0.8f));
    Assert::AreEqual(1, results.count(0.8f, 1));

    DetectionResults output = results.where(0.8f);
    Assert::AreEqual(static_cast<size_t>(2), output.size());
    Assert::AreEqual(result1, output[0]);
    Assert::AreEqual(result2, output[1]);

    output = results.where(0.8f, 1);
    Assert::AreEqual(static_cast<size_t>(1), output.size());
    Assert::AreEqual(result1, output[0]);
}
}  // namespace Detection
}  // namespace AutoMacro
