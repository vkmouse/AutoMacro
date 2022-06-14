#include "AutoMacroTest/Detection/TemplateBasedDetectorTest.h"

#include <functional>
#include <string>
#include <vector>

#include "AutoMacro/Detection/Detector.h"
#include "AutoMacro/Detection/DetectionResultsProcessor.h"
#include "AutoMacro/VideoCapture/VideoCapture.h"

namespace AutoMacro {
namespace Detection {
namespace {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;
}  // namesapce

void TemplateBasedDetectorTest::TestCreateTempateBasedDetector() {
    auto noTemplateFailed = std::bind(
            &Factory::createTemplateBasedDetector,
            std::vector<std::string>{});
    Assert::ExpectException<std::runtime_error>(noTemplateFailed);

    auto initializationFailed = std::bind(
        &Factory::createTemplateBasedDetector,
        std::vector<std::string>{ "abc.png" });
    Assert::ExpectException<std::runtime_error>(initializationFailed);

    Detector* detector = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTest\\Template_5x5_24bits.png",
    });
    Assert::IsNotNull(detector);
    delete(detector);
}

void TemplateBasedDetectorTest::TestTempateBasedDetector() {
    Detector* detector = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTest\\Template_5x5_24bits.png",
    });

    VideoCapture* capture = Factory::createImageFileCapture({
        "images\\AutoMacroTest\\ItemExists_10x10_24bits.png",
    });

    DetectionResults results = detector->detect(capture->takeSnapshot());

    Assert::AreEqual(static_cast<size_t>(1), results.size());
    Assert::IsTrue(itemExists(results, 0, 0.98f));
}
}  // namespace Detection
}  // namespace AutoMacro
