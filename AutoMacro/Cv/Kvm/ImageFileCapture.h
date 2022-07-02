#pragma once
#include <memory>
#include <string>
#include <vector>

#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
namespace Impl {
class ImageFileCapture : public BaseVideoCapture {
 public:
    explicit ImageFileCapture(std::vector<std::string> filenames);

 protected:
    virtual Image takeSnapshotWithoutPostprocessing();

 private:
    class Impl;
    std::unique_ptr<Impl> impl;
};
}  // namespace Impl
}  // namespace AutoMacro
