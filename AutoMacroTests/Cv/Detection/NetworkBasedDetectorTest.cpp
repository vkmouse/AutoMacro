#include <string>

#include "AutoMacro/Cv/Cv.h"
#include "AutoMacroTests/AssertExtension.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace DetectionTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

TEST_CLASS(NetworkBasedDetectorTest) {
const char* filename = "Models\\AutoMacroTests\\TestModel\\saved_model.bin";
const char* config = "Models\\AutoMacroTests\\TestModel\\saved_model.xml";
int width = 320;
int height = 320;

public:
TEST_METHOD(TestCreateNetworkBasedDetector) {
    auto detector = Factory::createNetworkBasedDetector(
        filename, config, width, height);
    Assert::IsTrue(detector != nullptr);
}

TEST_METHOD(TestNoModelFailed) {
    try {
        std::string filename = "abc.bin";
        std::string config = "abc.xml";
        Factory::createNetworkBasedDetector(filename, config, width, height);
    } catch (std::runtime_error ex) {
        return;
    }
    Assert::Fail();
}

TEST_METHOD(TestItemFound) {
    auto detector = Factory::createNetworkBasedDetector(
        filename, config, width, height);
    Image image =
        Cv::imread("images\\AutoMacroTests\\ItemExists_10x10_24bits.png");
    DetectionResults results = detector->detect(image);

    Assert::IsTrue(results.size() > 0);
    Assert::AreEqual(Rect(4, 2, 3, 3), results[0].region());
    Assert::IsTrue(results[0].confidence > 0.98f);
}

TEST_METHOD(TestItemNotFound) {
    auto detector = Factory::createNetworkBasedDetector(
        filename, config, width, height);
    Image image =
        Cv::imread("images\\AutoMacroTests\\ItemNotExists_10x10_24bits.png");
    DetectionResults results = detector->detect(image);

    Assert::IsTrue(results.size() > 0);
    Assert::IsTrue(results[0].confidence < 0.98f);
}
};
}  // namespace DetectionTest
}  // namespace AutoMacro
