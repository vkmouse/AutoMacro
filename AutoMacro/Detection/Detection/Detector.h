#pragma once
#include <memory>
#include <vector>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Detection/Detection/DetectionResults.h"
#include "AutoMacro/ImageProcessor/ImageProcessor.h"

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
    virtual void addPreprocessor(std::shared_ptr<ImageProcessor> processor) = 0;
    virtual void removeLastPreprocessor() = 0;

 protected:
    Detector() {}
};
}  // namespace Detection
}  // namespace AutoMacro
