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
        std::shared_ptr<Detector> detector, int index, float threshold)
        : ExecuteUntilItemCommandParameter(kvm, detector, index, threshold) {}

    int delayBetweenRepeatitions = 0;
};
}  // namespace AutoMacro
