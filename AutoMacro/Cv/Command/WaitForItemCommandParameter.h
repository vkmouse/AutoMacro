#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Cv/Command/CheckItemExistenceCommandFactory.h"

namespace AutoMacro {
class WaitForItemCommandParameter : public WhileCommandParameter {
 public:
    WaitForItemCommandParameter(Kvm kvm,
        std::shared_ptr<Detector> detector, int index, float threshold)
        : existenceParameter(kvm, detector, index, threshold),
          delayParameter(kvm) {}

    void setDelayBetweenRepeatitions(int value) {
        delayParameter.ms = value;
        executeCommand = Factory::createCommand(&delayParameter);
    }

    void setIsExpectedToExist(bool value) {
        existenceParameter.isExpectedToExist = value;
        requestCommand = Factory::createTCommand(&existenceParameter);
    }

 private:
    CheckItemExistenceCommandParameter existenceParameter;
    DelayCommandParameter delayParameter;
};
}  // namespace AutoMacro
