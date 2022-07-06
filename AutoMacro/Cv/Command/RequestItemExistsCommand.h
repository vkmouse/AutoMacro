#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Cv/Command/RequestItemExistsCommandParameter.h"

namespace AutoMacro {
namespace Impl {
class RequestItemExistsCommand : public KvmCommand<bool> {
 public:
    explicit RequestItemExistsCommand(RequestItemExistsCommandParameter* p);

 protected:
    virtual bool executeCommand();

 private:
    std::shared_ptr<Detector> detector_;
    int index_;
    float threshold_;
};
}  // namespace Impl
}  // namespace AutoMacro
