#include "AutoMacro/Command/WaitForItemsCommand.h"

#include <Windows.h>
#include <cassert>
#include <vector>

#include "AutoMacro/Core/pch.h"
#include "AutoMacro/Core/VideoCapture.h"
#include "AutoMacro/Command/Command.h"
#include "AutoMacro/Detection/Detector.h"
#include "AutoMacro/Detection/DetectionResultsProcessor.h"

namespace AutoMacro {
namespace Command {
class WaitForItemsCommand::Impl {
 public:
    Impl(VideoCapture* videoCapture,
        std::vector<Detection::Detector*> detectors,
        std::vector<int> indices,
        std::vector<float> thresholds) :
        videoCapture(videoCapture),
        detectors(detectors),
        indices(indices),
        thresholds(thresholds) {
    }

    VideoCapture* videoCapture;
    std::vector<Detection::Detector*> detectors;
    std::vector<int> indices;
    std::vector<float> thresholds;
};

WaitForItemsCommand::WaitForItemsCommand(
    VideoCapture* videoCapture,
    std::vector<Detection::Detector*> detectors,
    std::vector<int> indices,
    std::vector<float> thresholds) :
    impl(new Impl(videoCapture, detectors, indices, thresholds)) {
    assert(impl->detectors.size() == impl->indices.size());
    assert(impl->detectors.size() == impl->thresholds.size());
    numDetectors = static_cast<int>(detectors.size());
}

WaitForItemsCommand::~WaitForItemsCommand() {
}

void WaitForItemsCommand::executeCommand() {
    while (!testExpression()) {
        Sleep(delayBetweenRepeatitions);
    }
}

bool WaitForItemsCommand::testExpression() {
    Image image = impl->videoCapture->takeSnapshot();
    return (waitForAllItems && allItemsExists(image)) ||
        (!waitForAllItems && atLeastOneItemExists(image));
}

bool WaitForItemsCommand::allItemsExists(const Image& image) {
    for (int i = 0; i < numDetectors; i++) {
        if (itemExists(image, i) != waitForExists) {
            return false;
        }
    }
    return true;
}

bool WaitForItemsCommand::atLeastOneItemExists(const Image& image) {
    for (int i = 0; i < numDetectors; i++) {
        if (itemExists(image, i) == waitForExists) {
            return true;
        }
    }
    return false;
}

bool WaitForItemsCommand::itemExists(const Image& image, int detectorIndex) {
    auto results = impl->detectors[detectorIndex]->detect(image);
    int index = impl->indices[detectorIndex];
    float threshold = impl->thresholds[detectorIndex];
    return Detection::itemExists(results, index, threshold);
}
}  // namespace Command
}  // namespace AutoMacro
