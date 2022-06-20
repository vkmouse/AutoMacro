#pragma once
#include <memory>
#include <vector>

#include "AutoMacro/Command/Command/CommandParameter.h"
#include "AutoMacro/Command/Command/WaitForCommand.h"
#include "AutoMacro/Detection/Detection.h"

namespace AutoMacro {
namespace Command {
class WaitForItemsCommand : public WaitForCommand {
 public:
    explicit WaitForItemsCommand(WaitForItemsCommandParameter* p);

 protected:
    virtual bool testExpression();

 private:
    bool allItemsExists(const Image& image);
    bool atLeastOneItemExists(const Image& image);
    bool itemExists(const Image& image, int detectorIndex);

    std::vector<std::shared_ptr<Detection::Detector>> detectors;
    std::vector<int> indices;
    std::vector<float> thresholds;
    bool waitForAllItems;
    int numDetectors;
};
}  // namespace Command
}  // namespace AutoMacro
