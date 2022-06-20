#pragma once
#include <memory>

#include "AutoMacro/Command/Command/Command.h"
#include "AutoMacro/Command/Command/CommandParameter.h"
#include "AutoMacro/VideoCapture/VideoCapture.h"

namespace AutoMacro {
namespace Command {
class WaitForCommand : public Command {
 public:
    explicit WaitForCommand(WaitForCommandParameter* p);

 protected:
    virtual bool testExpression() = 0;

    virtual void executeCommand();

    std::shared_ptr<VideoCapture> videoCapture() const;
    bool waitForExists() const;

 private:
    std::shared_ptr<VideoCapture> videoCapture_;
    int delayBetweenRepeatitions_;
    bool waitForExists_;
};
}  // namespace Command
}  // namespace AutoMacro
