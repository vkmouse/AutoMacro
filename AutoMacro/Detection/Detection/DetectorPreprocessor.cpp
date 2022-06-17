#include "AutoMacro/Detection/Detection/DetectorPreprocessor.h"

#include "AutoMacro/Core/Image.h"
#include "AutoMacro/Detection/Detection/DetectionResult.h"
#include "AutoMacro/ImageProcessor/ImageProcessor.h"

namespace AutoMacro {
namespace Detection {
namespace Impl {
DetectorPreprocessor::DetectorPreprocessor(
	Detector* detector, 
	ImageProcessor* processor) :
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
