#pragma once
#include <memory>
#include <vector>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Command/Command.h"
#include "AutoMacro/Detection/Detection.h"

namespace AutoMacro {
namespace Command {
class WaitForItemsCommand : public Command {
 public:
    DLL_EXPORTS WaitForItemsCommand(
         std::shared_ptr<VideoCapture> videoCapture,
         std::vector<Detection::Detector*> detectors,
         std::vector<int> indices,
         std::vector<float> thresholds);

    DLL_EXPORTS virtual ~WaitForItemsCommand();

    int delayBetweenRepeatitions = 0;
    bool waitForExists = true;
    bool waitForAllItems = false;

 protected:
    virtual void executeCommand();

 private:
    bool testExpression();
    bool allItemsExists(const Image& image);
    bool atLeastOneItemExists(const Image& image);
    bool itemExists(const Image& image, int detectorIndex);

    class Impl;
    std::unique_ptr<Impl> impl;
    int numDetectors;
};
}  // namespace Command
}  // namespace AutoMacro
