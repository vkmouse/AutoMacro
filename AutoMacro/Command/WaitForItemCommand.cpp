#include "AutoMacro/Command/WaitForItemCommand.h"

#include <Windows.h>
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Detection/Detection.h"

namespace AutoMacro {
namespace Command {
WaitForItemCommand::WaitForItemCommand(
    std::shared_ptr<VideoCapture> videoCapture,
    std::shared_ptr<Detection::Detector> detector,
    int index,
    float threshold) :
    videoCapture(videoCapture),
    detector(detector),
    index(index),
    threshold(threshold),
    delayBetweenRepeatitions(0),
    waitForExists(true) {
}

void WaitForItemCommand::executeCommand() {
    while (itemExists() != waitForExists) {
        Sleep(delayBetweenRepeatitions);
    }
}

bool WaitForItemCommand::itemExists() {
    auto results = detector->detect(videoCapture->takeSnapshot());
    return Detection::itemExists(results, index, threshold);
}
}  // namespace Command
}  // namespace AutoMacro
