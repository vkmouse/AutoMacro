#pragma once
#include "AutoMacro/Core/pch.h"
#include "AutoMacro/Core/VideoCapture.h"
#include "AutoMacro/Command/Command.h"
#include "AutoMacro/Detection/Detector.h"

namespace AutoMacro {
namespace Command {
class DLL_EXPORTS WaitForItemCommand : public Command {
 public:
    WaitForItemCommand(
        VideoCapture* videoCapture,
        Detection::Detector* detector,
        int index,
        float threshold);

    virtual void executeCommand();

    VideoCapture* videoCapture;
    Detection::Detector* detector = nullptr;
    int index = 0;
    float threshold = 0.0f;
    int delayBetweenRepeatitions = 0;
    bool waitForExists = true;

 private:
    bool itemExists();
};
}  // namespace Command
}  // namespace AutoMacro
