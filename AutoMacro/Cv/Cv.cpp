#include "AutoMacro/Cv/Cv.h"

#include <string>

#include "opencv2/core.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
namespace Cv {
namespace {
Image matToImage(const cv::Mat& mat) {
    int channel = 0;
    if (mat.type() == CV_8UC4) {
        channel = 4;
    } else if (mat.type() == CV_8UC3) {
        channel = 3;
    } else if (mat.type() == CV_8UC1) {
        channel = 1;
    }

    return Image(mat.cols, mat.rows, channel, mat.data);
}

cv::Mat imageToMat(const Image& image) {
    int type = 0;
    if (image.channel() == 1) {
        type = CV_8UC1;
    } else if (image.channel() == 3) {
        type = CV_8UC3;
    } else if (image.channel() == 4) {
        type = CV_8UC4;
    }
    return cv::Mat(image.height(), image.width(), type, image.data());
}

cv::Rect toCvRect(const Rect rect) {
    return cv::Rect(rect.x, rect.y, rect.width, rect.height);
}
}  // namespace

Image imread(std::string filename) {
    cv::Mat mat = cv::imread(filename, cv::IMREAD_UNCHANGED);
    auto image = matToImage(mat);
    return image;
}

Image cropping(const Image& image, Rect region) {
    cv::Mat mat = imageToMat(image);
    mat = mat(toCvRect(region)).clone();
    return matToImage(mat);
}

Image convertToBGR(const Image& image) {
    cv::Mat mat = imageToMat(image);
    if (mat.type() == CV_8UC1) {
        cv::cvtColor(mat, mat, cv::COLOR_GRAY2BGR);
    } else if (mat.type() == CV_8UC4) {
        cv::cvtColor(mat, mat, cv::COLOR_BGRA2BGR);
    }
    return matToImage(mat);
}
}  // namespace Cv
}  // namespace AutoMacro
