#pragma once
#include <memory>
#include <string>
#include <vector>

#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
namespace Factory {
DLL_EXPORTS std::shared_ptr<VideoCapture> createImageFileCapture(
    std::vector<std::string> filenames);
}  // namespace Factory
}  // namespace AutoMacro
