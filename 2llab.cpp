#include <iostream>

class Point {
public:
    int x, y;
public:
    Point() : x(0), y(0) {
        std::cout << "Point()\n";
    }
    Point(int x, int y) : x(x), y(y) {
        std::cout << "Point(int x, int y)\n";
    }
    Point(const Point& p) : x(p.x), y(p.y) {
        std::cout << "Point(const Point& p)\n";
    }
    ~Point() {
        std::cout << x << ' ' << y << " ~Point()\n";
    }
    int getX() {
        return x;
    }
    int getY();
};

class ColoredPoint : public Point {
private:
    int color;
public:
    ColoredPoint() : Point(), color(0) {
        std::cout << "ColoredPoint()\n";
    }
    ColoredPoint(int x, int y, int color) : Point(x, y), color(color) {
        std::cout << "ColoredPoint(int x, int y)\n";
    }
    ColoredPoint(const ColoredPoint& p) : Point(p), color(p.color) {
        std::cout << "ColoredPoint(const ColoredPoint& p)\n";
    }
    ~ColoredPoint() {
        std::cout << x << ' ' << y << " color = " << color << " ~ColoredPoint()\n";
    }
};

int Point::getY() {
    return y;
}

int main() {
    {
        Point a();
        Point b(10, 10);
        Point c(b);
    }

    Point* a = new Point();
    Point* b = new Point(10, 10);
    Point* c = new Point(*b);
    delete a;
    delete b;
    delete c;

    {
        ColoredPoint a();
        ColoredPoint b(5, 10, 15);
        ColoredPoint c(b);
    }
}