#pragma once
#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Cv/Command/WaitForCommandParameter.h"

namespace AutoMacro {
namespace Impl {
class WaitForCommand : public Command {
 public:
    explicit WaitForCommand(WaitForCommandParameter* p);

 protected:
    virtual bool testExpression() = 0;

    virtual void executeCommand();

    bool waitForExists() const;

 private:
    int delayBetweenRepeatitions_;
    bool waitForExists_;
};
}  // namespace Impl
}  // namespace AutoMacro
