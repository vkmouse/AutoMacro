#include "AutoMacro/Cv/Cv.h"

#include <string>
#include <utility>
#include <vector>

#include "opencv2/core.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Cv/Command/WaitForItemCommand.h"
#include "AutoMacro/Cv/Command/WaitForItemCommandParameter.h"
#include "AutoMacro/Cv/Command/WaitForItemsCommand.h"
#include "AutoMacro/Cv/Command/WaitForItemsCommandParameter.h"
#include "AutoMacro/Cv/Detection/TemplateBasedDetector.h"
#include "AutoMacro/Cv/ImageProcessor/BGRConverterProcessor.h"
#include "AutoMacro/Cv/ImageProcessor/CroppingProcessor.h"
#include "AutoMacro/Cv/Kvm/ImageFileCapture.h"

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

namespace Factory {
std::shared_ptr<VideoCapture> createImageFileCapture(
        std::vector<std::string> filenames) {
    return std::make_shared<Impl::ImageFileCapture>(filenames);
}

std::shared_ptr<ImageProcessor> createBGRConverterProcessor() {
    return std::make_shared<Impl::BGRConverterProcessor>();
}

std::shared_ptr<ImageProcessor> createCroppingProcessor(
        int x, int y, int width, int height) {
    Rect region(x, y, width, height);
    return std::make_shared<Impl::CroppingProcessor>(region);
}

std::shared_ptr<ImageProcessor> createCroppingProcessor(Rect region) {
    return std::make_shared<Impl::CroppingProcessor>(region);
}

std::shared_ptr<Detector> createTemplateBasedDetector(
    std::vector<std::string> templatePaths, int numBoxes) {
    std::vector<std::pair<std::string, std::string>> templateAndMaskPaths;
    for (const auto& templatePath : templatePaths) {
        templateAndMaskPaths.push_back({ templatePath, "" });
    }
    auto detector = std::make_shared<Impl::TemplateBasedDetector>(
        templateAndMaskPaths, numBoxes);
    detector->init();
    return detector;
}

std::shared_ptr<Detector> createTemplateBasedDetector(
    std::vector<std::pair<std::string, std::string>> templateAndMaskPaths,
    int numBoxes) {
    auto detector = std::make_shared<Impl::TemplateBasedDetector>(
        templateAndMaskPaths, numBoxes);
    detector->init();
    return detector;
}

std::shared_ptr<Command> createCommand(
        WaitForItemCommandParameter* parameter) {
    return std::make_shared<Impl::WaitForItemCommand>(parameter);
}

std::shared_ptr<Command> createCommand(
        WaitForItemsCommandParameter* parameter) {
    return std::make_shared<Impl::WaitForItemsCommand>(parameter);
}
}  // namespace Factory
}  // namespace AutoMacro
