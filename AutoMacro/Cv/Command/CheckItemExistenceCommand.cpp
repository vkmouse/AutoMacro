#include "AutoMacro/Cv/Command/CheckItemExistenceCommand.h"

#include "AutoMacro/Cv/Command/CheckExistenceCommand.h"
#include "AutoMacro/Cv/Command/CheckItemExistenceCommandParameter.h"
#include "AutoMacro/Util/Util.h"

namespace AutoMacro {
namespace Impl {
CheckItemExistenceCommand::CheckItemExistenceCommand(
    CheckItemExistenceCommandParameter* p)
    : CheckExistenceCommand(p),
      detector_(p->detector),
      index_(p->index),
      threshold_(p->threshold) {
}

bool CheckItemExistenceCommand::executeCommand() {
    auto results = detector_->detect(takeSnapshot());
    return Util::exists(results, threshold_, index_) == isExpectedToExist();
}
}  // namespace Impl
}  // namespace AutoMacro
