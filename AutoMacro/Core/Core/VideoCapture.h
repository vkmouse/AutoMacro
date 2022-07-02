#pragma once
#include <memory>
#include <vector>

#include "AutoMacro/Core/Core/pch.h"
#include "AutoMacro/Core/Core/Image.h"
#include "AutoMacro/Core/Core/ImageProcessor.h"

namespace AutoMacro {
class DLL_EXPORTS VideoCapture {
 public:
    virtual ~VideoCapture() = default;

    virtual Image takeSnapshot() = 0;

    virtual void addPostprocessor(std::shared_ptr<ImageProcessor> processor) {}
    virtual void removeLastPostprocessor() {}
};

namespace Impl {
class BaseVideoCapture : public VideoCapture {
 public:
    Image takeSnapshot() final {
        Image image = takeSnapshotWithoutPostprocessing();
        for (const auto& processor : processors) {
            image = processor->process(image);
        }
        return image;
    }

    void addPostprocessor(std::shared_ptr<ImageProcessor> processor) final {
        processors.push_back(processor);
    }

    void removeLastPostprocessor() final {
        processors.pop_back();
    }

 protected:
    virtual Image takeSnapshotWithoutPostprocessing() = 0;

 private:
    std::vector<std::shared_ptr<ImageProcessor>> processors;
};
}  // namespace Impl
}  // namespace AutoMacro
