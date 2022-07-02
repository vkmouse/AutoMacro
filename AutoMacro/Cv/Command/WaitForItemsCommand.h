#pragma once
#include <memory>
#include <vector>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Cv/Command/WaitForCommand.h"
#include "AutoMacro/Cv/Command/WaitForItemsCommandParameter.h"

namespace AutoMacro {
namespace Impl {
class WaitForItemsCommand : public WaitForCommand {
 public:
    explicit WaitForItemsCommand(WaitForItemsCommandParameter* p);

 protected:
    virtual bool testExpression();

 private:
    bool allItemsExists(const Image& image);
    bool atLeastOneItemExists(const Image& image);
    bool itemExists(const Image& image, int detectorIndex);

    std::vector<std::shared_ptr<Detector>> detectors;
    std::vector<int> indices;
    std::vector<float> thresholds;
    bool waitForAllItems;
    int numDetectors;
};
}  // namespace Impl
}  // namespace AutoMacro
