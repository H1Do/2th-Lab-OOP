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

// композиция 1
class Square {
private:
    Point p1, p2; // точки на диагоналях
public:
    Square() : p1(), p2() {
        std::cout << "Square()\n";
    }
    Square(int x1, int y1, int x2, int y2) : p1(x1, y1), p2(x2, y2) {
        std::cout << "Square(int x1, int y1, int x2, int y2)\n";
    }
    Square(const Square& s1) : p1(s1.p1), p2(s1.p2) {
        std::cout << "Square(const Square& s1)\n";
    }
    ~Square() {
        std::cout << p1.x << ' ' << p1.y << ' ' << p2.x << ' ' << p2.y << "~Square() " << std::endl;
    }
};

// композиция 2
class Square {
private:
    Point* p1, * p2; // точки на диагоналях
public:
    Square() : p1(new Point()), p2(new Point()) {
        std::cout << "Square()\n";
    }
    Square(int x1, int y1, int x2, int y2) : p1(new Point(x1, y1)), p2(new Point(x2, y2)) {
        std::cout << "Square(int x1, int y1, int x2, int y2)\n";
    }
    Square(const Square& s1) : p1(new Point(*s1.p1)), p2(new Point(*s1.p2)) {
        std::cout << "Square(const Square& s1)\n";
    }
    ~Square() {
        std::cout << p1->x << ' ' << p1->y << ' ' << p2->x << ' ' << p2->y << "~Square() " << std::endl;
        delete p1;
        delete p2;
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

    /*
    Point* a = new Point();
    Point* b = new Point(10, 10);
    Point* c = new Point(*b);
    delete a;
    delete b;
    delete c;
    */

    /* {
        ColoredPoint a();
        ColoredPoint b(5, 10, 15);
        ColoredPoint c(b);
    }*/

    /*
    Point* a = new ColoredPoint(10, 5, 1);
    ColoredPoint* b = new ColoredPoint(10, 5, 1);
    delete a;
    delete b;
    */

    /*{
        Square a;
        Square b(5, 10, 15, 20);
        Square c(b);
    }*/

    /*Square* c = new Square;
    Square* a = new Square(10, 5, 3, 2);
    Square* b = new Square(*a);
    delete c;
    delete a;
    delete b;*/

    return 0;
}