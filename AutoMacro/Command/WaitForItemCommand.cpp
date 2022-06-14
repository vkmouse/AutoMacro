#include "AutoMacro/Command/WaitForItemCommand.h"

#include <Windows.h>

#include "AutoMacro/Core/VideoCapture.h"
#include "AutoMacro/Detection/Detector.h"
#include "AutoMacro/Detection/DetectionResultsProcessor.h"

namespace AutoMacro {
namespace Command {
WaitForItemCommand::WaitForItemCommand(
    VideoCapture* videoCapture,
    WaitForItemCommandParameter parameter) :
    videoCapture_(videoCapture) {
    detector_ = parameter.detector;
    index_ = parameter.index;
    threshold_ = parameter.threshold;
    delayBetweenRepeatitions_ = parameter.delayBetweenRepeatitions;
    waitForExists_ = parameter.waitForExists;
}

void WaitForItemCommand::execute() {
    while (itemExists() != waitForExists_) {
        Sleep(delayBetweenRepeatitions_);
    }
}

bool WaitForItemCommand::itemExists() {
    auto results = detector_->detect(videoCapture_->takeSnapshot());
    return Detection::itemExists(results, index_, threshold_);
}
}  // namespace Command
}  // namespace AutoMacro
