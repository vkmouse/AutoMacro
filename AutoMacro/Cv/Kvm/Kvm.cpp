#include "AutoMacro/Cv/Kvm/Kvm.h"

#include <memory>
#include <string>
#include <vector>

#include "AutoMacro/Cv/Kvm/ImageFileCapture.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<VideoCapture> createImageFileCapture(
        std::vector<std::string> filenames) {
    return std::make_shared<Impl::ImageFileCapture>(filenames);
}
}  // namespace Factory
}  // namespace AutoMacro
