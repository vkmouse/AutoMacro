#include "AutoMacroTest/Detection/DetectionPreprocessorTest.h"

#include <functional>

#include "CppUnitTest.h"
#include <AutoMacro/ImageProcessor/ImageProcessor.h>
#include <AutoMacro/Detection/Detector.h>
#include <AutoMacro/Detection/DetectionResult.h>
#include "AutoMacro/Detection/DetectionResultsProcessor.h"
#include "AutoMacro/VideoCapture/VideoCapture.h"

namespace AutoMacro {
namespace Detection {
namespace {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;
}  // namespace

void DetectionPreprocessorTest::TestBGRConverterProcessor() {
    Detector* detector = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTest\\Template_5x5_24bits.png",
    });

    VideoCapture* capture = Factory::createImageFileCapture({
        "images\\AutoMacroTest\\ItemExists_10x10_32bits.png",
    });
    
    auto channelNotEqualFailed = std::bind(&Detector::detect, detector, capture->takeSnapshot());
    Assert::ExpectException<std::runtime_error>(channelNotEqualFailed);

    ImageProcessor* processor = Factory::createBGRConverterProcessor();
    detector = Factory::addDetectorPreprocessing(detector, processor);
    DetectionResults results = detector->detect(capture->takeSnapshot());

    Assert::IsTrue(itemExists(results, 0, 0.98f));
}

void DetectionPreprocessorTest::TestCroppingProcessor() {
    Detector* detector = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTest\\Template_5x5_24bits.png",
    });

    VideoCapture* capture = Factory::createImageFileCapture({
        "images\\AutoMacroTest\\ItemExists_10x10_24bits.png",
    });

    DetectionResults results = detector->detect(capture->takeSnapshot());
    Assert::IsTrue(itemExists(results, 0, 0.98f));

    ImageProcessor* processor = Factory::createCroppingProcessor(3, 3, 7, 7);
    detector = Factory::addDetectorPreprocessing(detector, processor);
    results = detector->detect(capture->takeSnapshot());
    Assert::IsFalse(itemExists(results, 0, 0.98f));
}

void DetectionPreprocessorTest::TestMixedProcessor() {
    VideoCapture* capture = Factory::createImageFileCapture({
        "images\\AutoMacroTest\\ItemExists_10x10_32bits.png",
    });
    ImageProcessor* processor1 = Factory::createBGRConverterProcessor();
    ImageProcessor* processor2 = Factory::createCroppingProcessor(3, 3, 7, 7);

    Detector* detector = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTest\\Template_5x5_24bits.png",
    });
    detector = Factory::addDetectorPreprocessing(detector, processor1);
    detector = Factory::addDetectorPreprocessing(detector, processor2);
    DetectionResults results = detector->detect(capture->takeSnapshot());
    Assert::IsFalse(itemExists(results, 0, 0.98f));

    delete(detector);

    detector = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTest\\Template_5x5_24bits.png",
    });
    detector = Factory::addDetectorPreprocessing(detector, processor2);
    detector = Factory::addDetectorPreprocessing(detector, processor1);
    results = detector->detect(capture->takeSnapshot());
    Assert::IsFalse(itemExists(results, 0, 0.98f));
}
}  // namespace Detection
}  // namespace AutoMacro
