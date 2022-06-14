#pragma once
#include "AutoMacro/Core/pch.h"
#include "AutoMacro/Core/VideoCapture.h"
#include "AutoMacro/Command/Command.h"
#include "AutoMacro/Detection/Detector.h"

namespace AutoMacro {
namespace Command {
class DLL_EXPORTS WaitForItemCommandParameter {
 public:
    WaitForItemCommandParameter(
        Detection::Detector* detector, int index, float threshold) :
        detector(detector), index(index), threshold(threshold) {
    }

    Detection::Detector* detector = nullptr;
    int index = 0;
    float threshold = 0.0f;
    int delayBetweenRepeatitions = 0;
    bool waitForExists = true;
};

class DLL_EXPORTS WaitForItemCommand : public Command {
 public:
    WaitForItemCommand(
        VideoCapture* videoCapture,
        WaitForItemCommandParameter parameter);

    virtual void execute();

 private:
    bool itemExists();

    VideoCapture* videoCapture_;
    Detection::Detector* detector_ = nullptr;
    int index_ = 0;
    float threshold_ = 0.0f;
    int delayBetweenRepeatitions_ = 0;
    bool waitForExists_ = true;
};
}  // namespace Command
}  // namespace AutoMacro
