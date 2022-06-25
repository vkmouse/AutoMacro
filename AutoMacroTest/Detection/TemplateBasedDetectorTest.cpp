#include "AutoMacroTest/Detection/TemplateBasedDetectorTest.h"

#include <functional>
#include <memory>
#include <string>
#include <vector>

#include <AutoMacro/Cv/Cv.h>
#include <AutoMacro/Detection/Detection.h>
#include "AutoMacroTest/Assert/AssertExtension.h"

namespace AutoMacro {
namespace Detection {
namespace {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;
}  // namesapce

void TemplateBasedDetectorTest::TestCreateTempateBasedDetector() {
    auto detector = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTest\\Template_5x5_24bits.png",
    });
    Assert::IsTrue(detector != nullptr);
}

void TemplateBasedDetectorTest::TestNoTemplateFailed() {
    try {
        std::vector<std::string> filenames = {};
        Factory::createTemplateBasedDetector(filenames);
    } catch (std::runtime_error ex) {
        return;
    }
    Assert::Fail();
}

void TemplateBasedDetectorTest::TestInitializationFailed() {
    try {
        std::vector<std::string> filenames = { "abc.png" };
        Factory::createTemplateBasedDetector(filenames);
    } catch (std::runtime_error ex) {
        return;
    }
    Assert::Fail();
}

void TemplateBasedDetectorTest::TestTempateBasedDetector() {
    auto detector = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTest\\Template_5x5_24bits.png",
    });

    std::string filename = "images\\AutoMacroTest\\ItemExists_10x10_24bits.png";
    Image image = Cv::imread(filename);
    DetectionResults results = detector->detect(image);

    Assert::AreEqual(static_cast<size_t>(1), results.size());
    Assert::IsTrue(results.exists(0, 0.98f));
}

void TemplateBasedDetectorTest::TestNotExistTemplate() {
    auto detector = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTest\\NotExistedTemplate_5x5_24bits.png",
    });

    std::string filename = "images\\AutoMacroTest\\ItemExists_10x10_24bits.png";
    Image image = Cv::imread(filename);
    DetectionResults results = detector->detect(image);

    Assert::AreEqual(static_cast<size_t>(1), results.size());
    Assert::IsFalse(results.exists(0, 0.98f));
}

void TemplateBasedDetectorTest::TestTempateBasedDetectorWithMask() {
    TemplateBasedDetectorParameter parameter(
        "images\\AutoMacroTest\\NotExistedTemplate_5x5_24bits.png",
        "images\\AutoMacroTest\\NotExistedTemplateMask_5x5_24bits.png");
    auto detector = Factory::createTemplateBasedDetector({ parameter });

    std::string filename = "images\\AutoMacroTest\\ItemExists_10x10_24bits.png";
    Image image = Cv::imread(filename);
    DetectionResults results = detector->detect(image);

    Assert::AreEqual(static_cast<size_t>(1), results.size());
    Assert::IsTrue(results.exists(0, 0.98f));
}

void TemplateBasedDetectorTest::TestMultipleBoxes() {
    auto detector = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTest\\Template_5x5_24bits.png",
    }, 3);

    std::string filename = "images\\AutoMacroTest\\ItemExists_10x10_24bits.png";
    Image image = Cv::imread(filename);
    DetectionResults results = detector->detect(image);

    Assert::AreEqual(static_cast<size_t>(3), results.size());
    Assert::IsTrue(results.exists(0, 0.98f));

    Assert::AreNotEqual(results[0], results[1]);
    Assert::AreNotEqual(results[0], results[2]);
    Assert::AreNotEqual(results[1], results[2]);
}
}  // namespace Detection
}  // namespace AutoMacro
