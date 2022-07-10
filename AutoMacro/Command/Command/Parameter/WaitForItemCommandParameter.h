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
        : ExecuteUntilItemCommandParameter(kvm, detector, index, threshold),
          delayParameter(kvm) {
        executeCommand = Factory::createCommand(&delayParameter);
    }

    void setDelayBetweenRepeatitions(int value) {
        delayParameter.ms = value;
        executeCommand = Factory::createCommand(&delayParameter);
    }

 private:
    DelayCommandParameter delayParameter;
};
}  // namespace AutoMacro
