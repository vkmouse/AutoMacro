#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
class RequestItemExistsCommandParameter : public KvmCommandParameter {
 public:
    RequestItemExistsCommandParameter(Kvm kvm,
        std::shared_ptr<Detector> detector,
        int index, float threshold)
        : KvmCommandParameter(kvm),
          detector(detector),
          index(index),
          threshold(threshold) {}

    std::shared_ptr<Detector> detector;
    int index;
    float threshold;
};
}  // namespace AutoMacro
