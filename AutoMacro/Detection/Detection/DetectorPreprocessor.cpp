#include "AutoMacro/Detection/Detection/DetectorPreprocessor.h"

#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Detection/Detection/DetectionResults.h"
#include "AutoMacro/ImageProcessor/ImageProcessor.h"

namespace AutoMacro {
namespace Detection {
namespace Impl {
DetectorPreprocessor::DetectorPreprocessor(
    std::shared_ptr<Detector> detector,
    std::shared_ptr<ImageProcessor> processor) :
    detector_(detector),
    processor_(processor) {
}

DetectionResults DetectorPreprocessor::detect(Image image) {
    image = processor_->process(image);
    return detector_->detect(image);
}
}  // namespace Impl
}  // namespace Detection
}  // namespace AutoMacro
