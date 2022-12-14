#include "AutoMacro/Cv/Kvm/ImageFileCapture.h"

#include <cassert>
#include <string>
#include <vector>

#include "AutoMacro/Cv/Cv.h"
#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
namespace Impl {
class ImageFileCapture::Impl {
 public:
    explicit Impl(std::vector<std::string> filenames) :
        filenames_(filenames) {
        assert(filenames.size() > 0);
        current_ = filenames_.begin();
    }

    std::string current() {
        return *current_;
    }

    void next() {
        ++current_;
        if (current_ == filenames_.end()) {
            current_ = filenames_.begin();
        }
    }

 private:
    std::vector<std::string> filenames_;
    std::vector<std::string>::iterator current_;
};

ImageFileCapture::ImageFileCapture(std::vector<std::string> filenames) :
    impl(new Impl(filenames)) {
}

Image ImageFileCapture::takeSnapshotWithoutPostprocessing() {
    std::string filename = impl->current();
    Image image = Cv::imread(filename);
    impl->next();
    return image;
}
}  // namespace Impl
}  // namespace AutoMacro
