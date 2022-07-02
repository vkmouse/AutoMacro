#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Util/History/Histories.h"

namespace AutoMacro {
namespace Impl {
class DelayHistoryAgent : public Delay {
 public:
    DelayHistoryAgent(std::shared_ptr<Delay> delay,
                      Histories* histories);

    virtual void execute(int ms);

 private:
    std::shared_ptr<Delay> delay;
    Histories* histories;
};
}  // namespace Impl
}  // namespace AutoMacro
