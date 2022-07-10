#include "AutoMacro/Command/Command/Command/CheckItemsExistenceCommand.h"

#include "AutoMacro/Command/Command/Command/CheckExistenceCommand.h"
#include "AutoMacro/Command/Command/Parameter/CheckItemsExistenceCommandParameter.h"
#include "AutoMacro/Util/Util.h"

namespace AutoMacro {
namespace Impl {
CheckItemsExistenceCommand::CheckItemsExistenceCommand(
    CheckItemsExistenceCommandParameter* p)
    : CheckExistenceCommand(p),
      detectors_(p->detectors),
      indices_(p->indices),
      thresholds_(p->thresholds),
      isExpectedToAllExist_(p->isExpectedToAllExist) {
    numDetectors = static_cast<int>(detectors_.size());
}

bool CheckItemsExistenceCommand::executeCommand() {
    Image image = takeSnapshot();
    return (isExpectedToAllExist_ && allItemsExists(image)) ||
        (!isExpectedToAllExist_ && atLeastOneItemExists(image));
}

bool CheckItemsExistenceCommand::allItemsExists(const Image& image) {
    for (int i = 0; i < numDetectors; i++) {
        if (itemExists(image, i) != isExpectedToExist()) {
            return false;
        }
    }
    return true;
}

bool CheckItemsExistenceCommand::atLeastOneItemExists(const Image& image) {
    for (int i = 0; i < numDetectors; i++) {
        if (itemExists(image, i) == isExpectedToExist()) {
            return true;
        }
    }
    return false;
}

bool CheckItemsExistenceCommand::itemExists(const Image& image,
                                            int detectorIndex) {
    auto results = detectors_[detectorIndex]->detect(image);
    int index = indices_[detectorIndex];
    float threshold = thresholds_[detectorIndex];
    return Util::exists(results, threshold, index);
}
}  // namespace Impl
}  // namespace AutoMacro
