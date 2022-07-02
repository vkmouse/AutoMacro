#include "AutoMacro/Cv/Cv.h"
#include "AutoMacroTests/Cv/AssertExtension.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace KvmTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

TEST_CLASS(ImageFileCaptureTest) {
public:
TEST_METHOD(TestTakeSnapshot) {
    auto videoCapture = Factory::createImageFileCapture({
        "images\\AutoMacroTests\\Template_5x5_24bits.png",
        "images\\AutoMacroTests\\Sample_10x10_32bits.png",
    });
    Image image = videoCapture->takeSnapshot();
    Assert::AreEqual(5, image.width());
    Assert::AreEqual(5, image.height());
    Assert::AreEqual(3, image.channel());
    Assert::IsNotNull(image.data());

    image = videoCapture->takeSnapshot();
    Assert::AreEqual(10, image.width());
    Assert::AreEqual(10, image.height());
    Assert::AreEqual(4, image.channel());
    Assert::IsNotNull(image.data());
}

TEST_METHOD(TestCycleImages) {
    auto videoCapture = Factory::createImageFileCapture({
        "images\\AutoMacroTests\\Template_5x5_24bits.png",
        "images\\AutoMacroTests\\ItemExists_10x10_24bits.png"
    });
    int expected = 5;

    for (int i = 0; i < 10; i++) {
        Image image = videoCapture->takeSnapshot();
        Assert::AreEqual(expected, image.width());
        Assert::AreEqual(expected, image.height());
        Assert::AreEqual(3, image.channel());
        Assert::IsNotNull(image.data());
        expected = expected == 5 ? 10 : 5;
    }
}

TEST_METHOD(TestBGRConverterProcessor) {
    auto videoCapture = Factory::createImageFileCapture({
        "images\\AutoMacroTests\\Template_5x5_24bits.png",
        "images\\AutoMacroTests\\Sample_10x10_32bits.png",
    });
    auto processor = Factory::createBGRConverterProcessor();
    videoCapture->addPostprocessor(processor);
    for (int i = 0; i < 2; i++) {
        Image image = videoCapture->takeSnapshot();
        Assert::AreEqual(3, image.channel());
    }
}

TEST_METHOD(TestCroppingProcessor) {
    auto videoCapture = Factory::createImageFileCapture({
        "images\\AutoMacroTests\\Template_5x5_24bits.png",
        "images\\AutoMacroTests\\Sample_10x10_32bits.png",
    });
    auto processor = Factory::createCroppingProcessor(0, 0, 5, 5);
    videoCapture->addPostprocessor(processor);
    for (int i = 0; i < 2; i++) {
        Image image = videoCapture->takeSnapshot();
        Assert::AreEqual(5, image.width());
        Assert::AreEqual(5, image.height());
    }
}

TEST_METHOD(TestMixedProcessor) {
    auto videoCapture = Factory::createImageFileCapture({
        "images\\AutoMacroTests\\Template_5x5_24bits.png",
        "images\\AutoMacroTests\\Sample_10x10_32bits.png",
    });
    auto processor1 = Factory::createBGRConverterProcessor();
    auto processor2 = Factory::createCroppingProcessor(0, 0, 5, 5);
    videoCapture->addPostprocessor(processor1);
    videoCapture->addPostprocessor(processor2);
    for (int i = 0; i < 2; i++) {
        Image image = videoCapture->takeSnapshot();
        Assert::AreEqual(5, image.width());
        Assert::AreEqual(5, image.height());
        Assert::AreEqual(3, image.channel());
    }

    videoCapture = Factory::createImageFileCapture({
        "images\\AutoMacroTests\\Template_5x5_24bits.png",
        "images\\AutoMacroTests\\Sample_10x10_32bits.png",
    });
    videoCapture->addPostprocessor(processor2);
    videoCapture->addPostprocessor(processor1);
    for (int i = 0; i < 2; i++) {
        Image image = videoCapture->takeSnapshot();
        Assert::AreEqual(5, image.width());
        Assert::AreEqual(5, image.height());
        Assert::AreEqual(3, image.channel());
    }
}

TEST_METHOD(MultipleCropping) {
    auto videoCapture = Factory::createImageFileCapture({
        "images\\AutoMacroTests\\ItemExists_10x10_24bits.png",
    });

    auto processor1 = Factory::createCroppingProcessor(3, 1, 5, 5);
    auto processor2 = Factory::createCroppingProcessor(0, 0, 5, 5);

    videoCapture->addPostprocessor(processor1);
    videoCapture->addPostprocessor(processor2);

    Image expected =
        Cv::imread("images\\AutoMacroTests\\Template_5x5_24bits.png");

    Assert::AreEqual(expected, videoCapture->takeSnapshot());
}
};
}  // namespace KvmTest
}  // namespace AutoMacro
