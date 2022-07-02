#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Cv/Command/WaitForCommand.h"
#include "AutoMacro/Cv/Command/WaitForItemCommandParameter.h"

namespace AutoMacro {
namespace Impl {
class WaitForItemCommand : public WaitForCommand {
 public:
    explicit WaitForItemCommand(WaitForItemCommandParameter* p);

 protected:
    virtual bool testExpression();

 private:
    std::shared_ptr<Detector> detector;
    int index;
    float threshold;
};
}  // namespace Impl
}  // namespace AutoMacro
