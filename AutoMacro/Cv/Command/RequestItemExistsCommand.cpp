#include "AutoMacro/Cv/Command/RequestItemExistsCommand.h"

#include "AutoMacro/Cv/Command/RequestItemExistsCommandParameter.h"
#include "AutoMacro/Util/Util.h"

namespace AutoMacro {
namespace Impl {
RequestItemExistsCommand::RequestItemExistsCommand(
    RequestItemExistsCommandParameter* p)
    : KvmCommand(p),
      detector_(p->detector),
      index_(p->index),
      threshold_(p->threshold) {
}

bool RequestItemExistsCommand::executeCommand() {
    auto results = detector_->detect(takeSnapshot());
    return Util::exists(results, threshold_, index_);
}
}  // namespace Impl
}  // namespace AutoMacro
