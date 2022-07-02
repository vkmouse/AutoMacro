#include "AutoMacro/Core/Core/Types.h"

namespace AutoMacro {
Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

bool Point::operator==(const Point& other) const {
    return x == other.x && y == other.y;
}

Rect::Rect() {
    x = 0;
    y = 0;
    width = 0;
    height = 0;
}

Rect::Rect(int x, int y, int width, int height) :
    x(x), y(y), width(width), height(height) {
}

bool Rect::operator==(const Rect& other) const {
    return other.x == x &&
        other.y == y &&
        other.width == width &&
        other.height == height;
}

bool Rect::contain(Point point) const {
    return x <= point.x && point.x <= x + width &&
        y <= point.y && point.y <= y + height;
}

Point Rect::center() const {
    return { x + width / 2, y + height / 2 };
}

int Rect::left() const {
    return x;
}

int Rect::right() const {
    return x + width;
}

int Rect::top() const {
    return y;
}

int Rect::bottom() const {
    return y + height;
}

int Rect::area() const {
    return width * height;
}
}  // namespace AutoMacro
