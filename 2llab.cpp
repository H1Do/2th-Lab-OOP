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

int Point::getY() {
    return y;
}

int main() {
    {
        Point a();
        Point b(10, 10);
        Point c(b);
    }
}