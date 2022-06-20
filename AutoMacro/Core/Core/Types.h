#pragma once
#include "AutoMacro/Core/Core/pch.h"

namespace AutoMacro {
class DLL_EXPORTS Point {
 public:
    Point();
    Point(int x, int y);

    bool operator==(const Point& other) const;

    int x;
    int y;
};

class DLL_EXPORTS Rect {
 public:
    Rect();
    Rect(int x, int y, int width, int height);

    bool operator==(const Rect& other) const;

    bool contain(Point point) const;
    Point center() const;
    int left() const;
    int right() const;
    int top() const;
    int bottom() const;
    int area() const;

    int x;
    int y;
    int width;
    int height;
};
}  // namespace AutoMacro
