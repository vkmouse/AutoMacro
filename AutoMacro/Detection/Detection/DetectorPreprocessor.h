#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Detection/Detection/Detector.h"
#include "AutoMacro/Detection/Detection/DetectionResult.h"
#include "AutoMacro/ImageProcessor/ImageProcessor.h"

namespace AutoMacro {
namespace Detection {
namespace Impl {
class DetectorPreprocessor : public Detector {
 public:
	DetectorPreprocessor(Detector* detector, std::shared_ptr<ImageProcessor> processor);

	virtual DetectionResults detect(Image image);

 private:
	Detector* detector_;
	std::shared_ptr<ImageProcessor> processor_;
};
}  // namespace Impl
}  // namespace Detection
}  // namespace AutoMacro
