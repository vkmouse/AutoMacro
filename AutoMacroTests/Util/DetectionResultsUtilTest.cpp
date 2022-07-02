#include "AutoMacro/Util/Util.h"
#include "CppUnitTest.h"

namespace Microsoft {
namespace VisualStudio {
namespace CppUnitTestFramework {
std::wstring ToString(AutoMacro::DetectionResult value) {
    std::wstring str = std::to_wstring(value.index);
    str += std::to_wstring(value.x);
    str += std::to_wstring(value.y);
    str += std::to_wstring(value.width);
    str += std::to_wstring(value.height);
    str += std::to_wstring(value.confidence);
    return str;
}
}  // namespace CppUnitTestFramework
}  // namespace VisualStudio
}  // namespace Microsoft


namespace AutoMacro {
namespace {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;
}  // namespace

TEST_CLASS(HistoryTest) {
public:
TEST_METHOD(TestExists) {
    DetectionResult result1;
    result1.index = 1;
    result1.confidence = 0.9f;

    DetectionResult result2;
    result2.index = 2;
    result2.confidence = 0.5f;

    DetectionResults a;
    DetectionResults results;
    results.push_back(result1);
    results.push_back(result2);

    Assert::IsTrue(Util::exists(results, 0.8f));
    Assert::IsFalse(Util::exists(results, 0.95f));
    Assert::IsTrue(Util::exists(results, 0.8f, 1));
    Assert::IsFalse(Util::exists(results, 0.8f, 2));
}

TEST_METHOD(TestCountAndWhere) {
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

    Assert::AreEqual(2, Util::count(results, 0.8f));
    Assert::AreEqual(1, Util::count(results, 0.8f, 1));

    auto output = Util::where(results, 0.8f);
    Assert::AreEqual(static_cast<size_t>(2), output.size());
    Assert::AreEqual(result1, output[0]);
    Assert::AreEqual(result2, output[1]);

    output = Util::where(results, 0.8f, 1);
    Assert::AreEqual(static_cast<size_t>(1), output.size());
    Assert::AreEqual(result1, output[0]);
}
};
}  // namespace AutoMacro
