#include "AutoMacro/Command/WaitForItemCommand.h"

#include <Windows.h>

#include "AutoMacro/Core/VideoCapture.h"
#include "AutoMacro/Detection/Detection.h"

namespace AutoMacro {
namespace Command {
WaitForItemCommand::WaitForItemCommand(
    VideoCapture* videoCapture,
    Detection::Detector* detector,
    int index,
    float threshold) :
    videoCapture(videoCapture),
    detector(detector),
    index(index),
    threshold(threshold),
    delayBetweenRepeatitions(delayBetweenRepeatitions),
    waitForExists(waitForExists) {
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
