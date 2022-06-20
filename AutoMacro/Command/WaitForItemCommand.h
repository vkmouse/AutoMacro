#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Command/Command.h"
#include "AutoMacro/Detection/Detection.h"

namespace AutoMacro {
namespace Command {
class WaitForItemCommand : public Command {
 public:
    DLL_EXPORTS WaitForItemCommand(
        std::shared_ptr<VideoCapture> videoCapture,
        std::shared_ptr<Detection::Detector> detector,
        int index,
        float threshold);

    int delayBetweenRepeatitions = 0;
    bool waitForExists = true;

 protected:
    virtual void executeCommand();

 private:
    bool itemExists();

    std::shared_ptr<VideoCapture> videoCapture;
    std::shared_ptr<Detection::Detector> detector;
    int index;
    float threshold;
};
}  // namespace Command
}  // namespace AutoMacro
