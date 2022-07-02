#include "AutoMacro/Core/Core.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace CoreTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

TEST_CLASS(TypesTest) {
TEST_METHOD(TestPoint) {
    Point p1;
    Assert::AreEqual(0, p1.x);
    Assert::AreEqual(0, p1.y);

    Point p2(1, 2);
    Assert::AreEqual(1, p2.x);
    Assert::AreEqual(2, p2.y);
    Assert::IsFalse(p1 == p2);

    Point p3(1, 2);
    Assert::IsTrue(p2 == p3);
}

TEST_METHOD(TestRect) {
    Rect r1;
    Assert::AreEqual(0, r1.x);
    Assert::AreEqual(0, r1.y);
    Assert::AreEqual(0, r1.width);
    Assert::AreEqual(0, r1.height);

    Rect r2(2, 3, 4, 5);
    Assert::AreEqual(2, r2.x);
    Assert::AreEqual(3, r2.y);
    Assert::AreEqual(4, r2.width);
    Assert::AreEqual(5, r2.height);
    Assert::IsFalse(r1 == r2);

    Rect r3(2, 3, 4, 5);
    Assert::IsTrue(r2 == r3);
}

TEST_METHOD(TestRectFunction) {
    Rect rect(2, 3, 4, 5);
    Assert::AreEqual(2, rect.left());
    Assert::AreEqual(6, rect.right());
    Assert::AreEqual(3, rect.top());
    Assert::AreEqual(8, rect.bottom());
    Assert::AreEqual(20, rect.area());

    Point p1(3, 4);
    Point p2(0, 4);
    Assert::IsTrue(rect.contain(p1));
    Assert::IsFalse(rect.contain(p2));

    Rect r1(3, 5, 10, 10);
    Point center1(8, 10);
    Assert::IsTrue(center1 == r1.center());

    Rect r2(2, 1, 3, 5);
    Point center2(3, 3);
    Assert::IsTrue(center2 == r2.center());
}
};
}  // namespace CoreTest
}  // namespace AutoMacro
