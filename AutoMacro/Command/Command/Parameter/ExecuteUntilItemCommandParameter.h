#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Command/Command/Parameter/CheckItemExistenceCommandParameter.h"
#include "AutoMacro/Command/Command/Parameter/ExecuteUntilCommandParameter.h"

namespace AutoMacro {
class ExecuteUntilItemCommandParameter
    : public ExecuteUntilCommandParameter,
      public CheckItemExistenceCommandParameter {
 public:
    ExecuteUntilItemCommandParameter(Kvm kvm,
        std::shared_ptr<Detector> detector, int index, float threshold)
        : CheckItemExistenceCommandParameter(kvm, detector, index, threshold) {}

    ExecuteUntilItemCommandParameter(Kvm kvm,
        std::shared_ptr<Detector> detector, int index, float threshold,
        std::shared_ptr<Command> executeCommand)
        : CheckItemExistenceCommandParameter(kvm, detector, index, threshold),
          ExecuteUntilCommandParameter(executeCommand, nullptr) {}
};
}  // namespace AutoMacro
