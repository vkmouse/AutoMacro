#pragma once
#include <memory>
#include <vector>

#include "AutoMacro/Detection/Detection.h"
#include "AutoMacro/Keyboard/Keyboard.h"
#include "AutoMacro/VideoCapture/VideoCapture.h"

namespace AutoMacro {
namespace Command {
class CommandParameter {
 public:
    int delayBeforeCommand = 0;
    int delayAfterCommand = 0;
};

class WaitForCommandParameter : public CommandParameter {
 public:
    WaitForCommandParameter(
        std::shared_ptr<VideoCapture> videoCapture) :
        videoCapture(videoCapture) {}

    std::shared_ptr<VideoCapture> videoCapture;
    int delayBetweenRepeatitions = 0;
    bool waitForExists = true;
};

class WaitForItemCommandParameter : public WaitForCommandParameter {
 public:
     WaitForItemCommandParameter(
         std::shared_ptr<VideoCapture> videoCapture,
         std::shared_ptr<Detection::Detector> detector,
         int index,
         float threshold) :
         WaitForCommandParameter(videoCapture),
         detector(detector),
         index(index),
         threshold(threshold) {}

    std::shared_ptr<Detection::Detector> detector;
    int index;
    float threshold;
};

class WaitForItemsCommandParameter : public WaitForCommandParameter {
 public:
     WaitForItemsCommandParameter(
         std::shared_ptr<VideoCapture> videoCapture,
         std::vector<std::shared_ptr<Detection::Detector>> detectors,
         std::vector<int> indices,
         std::vector<float> thresholds) :
         WaitForCommandParameter(videoCapture),
         detectors(detectors),
         indices(indices),
         thresholds(thresholds) {}

    std::vector<std::shared_ptr<Detection::Detector>> detectors;
    std::vector<int> indices;
    std::vector<float> thresholds;
    bool waitForAllItems = false;
};

class SendKeyCommandParameter : public CommandParameter {
 public:
    SendKeyCommandParameter(
        std::shared_ptr<Keyboard> keyboard, KeyCode key) :
        keyboard(keyboard), key(key) {}

    std::shared_ptr<Keyboard> keyboard;
    KeyCode key;
    int delayBetweenCommands = 0;
    int delayBetweenRepeatitions = 0;
    int repeatTimes = 1;
};

}  // namespace Command
}  // namespace AutoMacro
