#pragma once
#include <memory>
#include <string>
#include <vector>

#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
namespace Impl {
class ImageFileCapture : public VideoCapture {
 public:
    DLL_EXPORTS ImageFileCapture(std::vector<std::string> filenames);

    virtual DLL_EXPORTS Image takeSnapshot();

 private:
    class Impl;
    std::unique_ptr<Impl> impl;
};
}  // namespace Impl
}  // namespace AutoMacro
