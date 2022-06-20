#pragma once
#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Command/Command.h"
#include "AutoMacro/Detection/Detection.h"

namespace AutoMacro {
namespace Command {
class DLL_EXPORTS WaitForItemCommand : public Command {
 public:
    WaitForItemCommand(
        VideoCapture* videoCapture,
        Detection::Detector* detector,
        int index,
        float threshold);

    int delayBetweenRepeatitions = 0;
    bool waitForExists = true;

 protected:
    virtual void executeCommand();

 private:
    bool itemExists();

    VideoCapture* videoCapture;
    Detection::Detector* detector;
    int index;
    float threshold;
};
}  // namespace Command
}  // namespace AutoMacro
