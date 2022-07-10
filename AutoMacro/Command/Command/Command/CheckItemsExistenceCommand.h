#pragma once
#include <memory>
#include <vector>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Command/Command/Command/CheckExistenceCommand.h"
#include "AutoMacro/Command/Command/Parameter/CheckItemsExistenceCommandParameter.h"

namespace AutoMacro {
namespace Impl {
class CheckItemsExistenceCommand : public CheckExistenceCommand {
 public:
    explicit CheckItemsExistenceCommand(CheckItemsExistenceCommandParameter* p);

 protected:
    virtual bool executeCommand();

 private:
    bool allItemsExists(const Image& image);
    bool atLeastOneItemExists(const Image& image);
    bool itemExists(const Image& image, int detectorIndex);

    std::vector<std::shared_ptr<Detector>> detectors_;
    std::vector<int> indices_;
    std::vector<float> thresholds_;
    bool isExpectedToAllExist_;

    int numDetectors;
};
}  // namespace Impl
}  // namespace AutoMacro
