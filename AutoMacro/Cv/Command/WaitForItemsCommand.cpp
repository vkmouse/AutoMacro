#include "AutoMacro/Cv/Command/WaitForItemsCommand.h"

#include <cassert>
#include <vector>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Cv/Command/WaitForItemsCommandParameter.h"
#include "AutoMacro/Util/Util.h"

namespace AutoMacro {
namespace Impl {
WaitForItemsCommand::WaitForItemsCommand(WaitForItemsCommandParameter* p) :
    WaitForCommand(p),
    detectors(p->detectors),
    indices(p->indices),
    thresholds(p->thresholds),
    waitForAllItems(p->waitForAllItems) {
    assert(detectors.size() == indices.size());
    assert(detectors.size() == thresholds.size());
    numDetectors = static_cast<int>(detectors.size());
}

bool WaitForItemsCommand::testExpression() {
    Image image = takeSnapshot();
    return (waitForAllItems && allItemsExists(image)) ||
        (!waitForAllItems && atLeastOneItemExists(image));
}

bool WaitForItemsCommand::allItemsExists(const Image& image) {
    for (int i = 0; i < numDetectors; i++) {
        if (itemExists(image, i) != waitForExists()) {
            return false;
        }
    }
    return true;
}

bool WaitForItemsCommand::atLeastOneItemExists(const Image& image) {
    for (int i = 0; i < numDetectors; i++) {
        if (itemExists(image, i) == waitForExists()) {
            return true;
        }
    }
    return false;
}

bool WaitForItemsCommand::itemExists(const Image& image, int detectorIndex) {
    auto results = detectors[detectorIndex]->detect(image);
    int index = indices[detectorIndex];
    float threshold = thresholds[detectorIndex];
    return Util::exists(results, threshold, index);
}
}  // namespace Impl
}  // namespace AutoMacro
