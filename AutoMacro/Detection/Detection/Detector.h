#pragma once
#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Detection/Detection/DetectionResult.h"

namespace AutoMacro {
namespace Detection {
class DLL_EXPORTS Detector {
 public:
    Detector(Detector&& other) = default;
    Detector(const Detector&) = delete;

    Detector& operator=(Detector&& other) = default;
    Detector& operator=(const Detector&) = delete;

    virtual ~Detector() {}

    virtual void init() {}
    virtual DetectionResults detect(Image image) = 0;

 protected:
    Detector() {}
};
}  // namespace Detection
}  // namespace AutoMacro
