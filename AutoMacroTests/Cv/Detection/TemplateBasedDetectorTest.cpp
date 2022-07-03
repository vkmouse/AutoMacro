#include <functional>
#include <memory>
#include <string>
#include <vector>

#include "AutoMacro/Cv/Cv.h"
#include "AutoMacro/Util/Util.h"
#include "AutoMacroTests/AssertExtension.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace DetectionTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

TEST_CLASS(TemplateBasedDetectorTest) {
public:
TEST_METHOD(TestCreateTempateBasedDetector) {
    auto detector = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTests\\Template_5x5_24bits.png",
    });
    Assert::IsTrue(detector != nullptr);
}

TEST_METHOD(TestNoTemplateFailed) {
    try {
        std::vector<std::string> filenames = {};
        Factory::createTemplateBasedDetector(filenames);
    } catch (std::runtime_error ex) {
        return;
    }
    Assert::Fail();
}

TEST_METHOD(TestInitializationFailed) {
    try {
        std::vector<std::string> filenames = { "abc.png" };
        Factory::createTemplateBasedDetector(filenames);
    } catch (std::runtime_error ex) {
        return;
    }
    Assert::Fail();
}

TEST_METHOD(TestTempateBasedDetector) {
    auto detector = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTests\\Template_5x5_24bits.png",
    });

    Image image =
        Cv::imread("images\\AutoMacroTests\\ItemExists_10x10_24bits.png");
    DetectionResults results = detector->detect(image);

    Assert::AreEqual(static_cast<size_t>(1), results.size());
    Assert::IsTrue(Util::exists(results, 0.98f, 0));
}

TEST_METHOD(TestNotExistTemplate) {
    auto detector = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTests\\NotExistedTemplate_5x5_24bits.png",
    });

    Image image =
        Cv::imread("images\\AutoMacroTests\\ItemExists_10x10_24bits.png");
    DetectionResults results = detector->detect(image);

    Assert::AreEqual(static_cast<size_t>(1), results.size());
    Assert::IsFalse(Util::exists(results, 0.98f, 0));
}

TEST_METHOD(TestTempateBasedDetectorWithMask) {
    std::pair<std::string, std::string> templateAndMaskPath(
        "images\\AutoMacroTests\\NotExistedTemplate_5x5_24bits.png",
        "images\\AutoMacroTests\\NotExistedTemplateMask_5x5_24bits.png");
    auto detector = Factory::createTemplateBasedDetector({
        templateAndMaskPath });

    Image image =
        Cv::imread("images\\AutoMacroTests\\ItemExists_10x10_24bits.png");
    DetectionResults results = detector->detect(image);

    Assert::AreEqual(static_cast<size_t>(1), results.size());
    Assert::IsTrue(Util::exists(results, 0.98f, 0));
}

TEST_METHOD(TestMultipleBoxes) {
    auto detector = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTests\\Template_5x5_24bits.png",
    }, 3);

    Image image =
        Cv::imread("images\\AutoMacroTests\\ItemExists_10x10_24bits.png");
    DetectionResults results = detector->detect(image);

    Assert::AreEqual(static_cast<size_t>(3), results.size());
    Assert::IsTrue(Util::exists(results, 0.98f, 0));

    Assert::AreNotEqual(results[0], results[1]);
    Assert::AreNotEqual(results[0], results[2]);
    Assert::AreNotEqual(results[1], results[2]);
}

TEST_METHOD(TestMultipleTemplates) {
    std::vector<std::string> templates = {
        "images\\AutoMacroTests\\Template_5x5_24bits.png",
        "images\\AutoMacroTests\\Template_5x5_24bits.png"
    };
    auto detector = Factory::createTemplateBasedDetector(templates);

    Image image =
        Cv::imread("images\\AutoMacroTests\\ItemExists_10x10_24bits.png");
    DetectionResults results = detector->detect(image);

    Assert::AreEqual(static_cast<size_t>(2), results.size());
    Assert::IsTrue(Util::exists(results, 0.98f, 0));

    Assert::AreEqual(0, results[0].index);
    Assert::AreEqual(1, results[1].index);
    Assert::AreEqual(results[0].confidence, results[1].confidence);
}

TEST_METHOD(TestBGRConverterProcessor) {
    auto detector = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTests\\Template_5x5_24bits.png",
    });

    auto capture = Factory::createImageFileCapture({
        "images\\AutoMacroTests\\ItemExists_10x10_32bits.png",
    });

    auto channelNotEqualFailed =
        std::bind(&Detector::detect, detector, capture->takeSnapshot());
    Assert::ExpectException<std::runtime_error>(channelNotEqualFailed);

    auto processor = Factory::createBGRConverterProcessor();
    detector->addPreprocessor(processor);
    DetectionResults results = detector->detect(capture->takeSnapshot());

    Assert::IsTrue(Util::exists(results, 0.98f, 0));
}

TEST_METHOD(TestCroppingProcessor) {
    auto detector = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTests\\Template_5x5_24bits.png",
    });

    auto capture = Factory::createImageFileCapture({
        "images\\AutoMacroTests\\ItemExists_10x10_24bits.png",
    });

    DetectionResults results = detector->detect(capture->takeSnapshot());
    Assert::IsTrue(Util::exists(results, 0.98f, 0));

    auto processor = Factory::createCroppingProcessor(3, 3, 7, 7);
    detector->addPreprocessor(processor);
    results = detector->detect(capture->takeSnapshot());
    Assert::IsFalse(Util::exists(results, 0.98f, 0));

    detector->removeLastPreprocessor();
    results = detector->detect(capture->takeSnapshot());
    Assert::IsTrue(Util::exists(results, 0.98f, 0));
}

TEST_METHOD(TestMixedProcessor) {
    auto capture = Factory::createImageFileCapture({
        "images\\AutoMacroTests\\ItemExists_10x10_32bits.png",
    });
    auto processor1 = Factory::createBGRConverterProcessor();
    auto processor2 = Factory::createCroppingProcessor(3, 3, 7, 7);

    auto detector = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTests\\Template_5x5_24bits.png",
    });
    detector->addPreprocessor(processor1);
    detector->addPreprocessor(processor2);
    DetectionResults results = detector->detect(capture->takeSnapshot());
    Assert::IsFalse(Util::exists(results, 0.98f, 0));

    detector = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTests\\Template_5x5_24bits.png",
    });
    detector->addPreprocessor(processor2);
    detector->addPreprocessor(processor1);
    results = detector->detect(capture->takeSnapshot());
    Assert::IsFalse(Util::exists(results, 0.98f, 0));
}

TEST_METHOD(TestMultipleCroppingProcessor) {
    auto detector = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTests\\Template_5x5_24bits.png",
    });

    auto capture = Factory::createImageFileCapture({
        "images\\AutoMacroTests\\ItemExists_10x10_24bits.png",
    });

    auto processor1 = Factory::createCroppingProcessor(3, 1, 5, 5);
    detector->addPreprocessor(processor1);
    auto results = detector->detect(capture->takeSnapshot());
    Assert::IsTrue(Util::exists(results, 0.98f, 0));

    auto processor2 = Factory::createCroppingProcessor(0, 0, 5, 5);
    detector->addPreprocessor(processor2);
    results = detector->detect(capture->takeSnapshot());
    Assert::IsTrue(Util::exists(results, 0.98f, 0));
}
};
}  // namespace DetectionTest
}  // namespace AutoMacro
