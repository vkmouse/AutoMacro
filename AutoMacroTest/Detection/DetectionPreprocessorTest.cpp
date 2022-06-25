#include "AutoMacroTest/Detection/DetectionPreprocessorTest.h"

#include <functional>
#include <memory>

#include "CppUnitTest.h"
#include <AutoMacro/ImageProcessor/ImageProcessor.h>
#include <AutoMacro/Detection/Detection.h>
#include <AutoMacro/VideoCapture/VideoCapture.h>

namespace AutoMacro {
namespace Detection {
namespace {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;
}  // namespace

void DetectionPreprocessorTest::TestBGRConverterProcessor() {
    auto detector = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTest\\Template_5x5_24bits.png",
    });

    auto capture = Factory::createImageFileCapture({
        "images\\AutoMacroTest\\ItemExists_10x10_32bits.png",
    });

    auto channelNotEqualFailed =
        std::bind(&Detector::detect, detector, capture->takeSnapshot());
    Assert::ExpectException<std::runtime_error>(channelNotEqualFailed);

    auto processor = Factory::createBGRConverterProcessor();
    detector = Factory::addPreprocessing(detector, processor);
    DetectionResults results = detector->detect(capture->takeSnapshot());

    Assert::IsTrue(results.exists(0.98f, 0));
}

void DetectionPreprocessorTest::TestCroppingProcessor() {
    auto detector = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTest\\Template_5x5_24bits.png",
    });

    auto capture = Factory::createImageFileCapture({
        "images\\AutoMacroTest\\ItemExists_10x10_24bits.png",
    });

    DetectionResults results = detector->detect(capture->takeSnapshot());
    Assert::IsTrue(results.exists(0.98f, 0));

    auto processor = Factory::createCroppingProcessor(3, 3, 7, 7);
    detector = Factory::addPreprocessing(detector, processor);
    results = detector->detect(capture->takeSnapshot());
    Assert::IsFalse(results.exists(0.98f, 0));
}

void DetectionPreprocessorTest::TestMixedProcessor() {
    auto capture = Factory::createImageFileCapture({
        "images\\AutoMacroTest\\ItemExists_10x10_32bits.png",
    });
    auto processor1 = Factory::createBGRConverterProcessor();
    auto processor2 = Factory::createCroppingProcessor(3, 3, 7, 7);

    auto detector = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTest\\Template_5x5_24bits.png",
    });
    detector = Factory::addPreprocessing(detector, processor1);
    detector = Factory::addPreprocessing(detector, processor2);
    DetectionResults results = detector->detect(capture->takeSnapshot());
    Assert::IsFalse(results.exists(0.98f, 0));

    detector = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTest\\Template_5x5_24bits.png",
        });
    detector = Factory::addPreprocessing(detector, processor2);
    detector = Factory::addPreprocessing(detector, processor1);
    results = detector->detect(capture->takeSnapshot());
    Assert::IsFalse(results.exists(0.98f, 0));
}
}  // namespace Detection
}  // namespace AutoMacro
