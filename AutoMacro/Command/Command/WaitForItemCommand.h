#pragma once
#include <memory>

#include "AutoMacro/Command/Command/CommandParameter.h"
#include "AutoMacro/Command/Command/WaitForCommand.h"
#include "AutoMacro/Detection/Detection.h"

namespace AutoMacro {
namespace Command {
class WaitForItemCommand : public WaitForCommand {
 public:
    explicit WaitForItemCommand(WaitForItemCommandParameter* p);

 protected:
    virtual bool testExpression();

 private:
    std::shared_ptr<Detection::Detector> detector;
    int index;
    float threshold;
};
}  // namespace Command
}  // namespace AutoMacro
