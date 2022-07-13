#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Command/Command/Factory/DelayCommandFactory.h"
#include "AutoMacro/Command/Command/Factory/EmptyCommandFactory.h"
#include "AutoMacro/Command/Command/Parameter/ExecuteUntilItemCommandParameter.h"

namespace AutoMacro {
class WaitForItemCommandParameter : public ExecuteUntilItemCommandParameter {
 public:
    WaitForItemCommandParameter(Kvm kvm,
        std::shared_ptr<Detector> detector, float threshold)
        : ExecuteUntilItemCommandParameter(kvm, detector, threshold) {}

    int delayBetweenRepeatitions = 0;
};
}  // namespace AutoMacro
