#include <iostream>
using namespace std;

class Informer {
public:
    Informer() {
        //std::cout << "Konstruktor" << '\n';
    }
    ~Informer() {
        //std::cout << "Destruktor" << '\n';
    }
};

class Wektor2D {
public:
    Wektor2D() {};
    Informer inf;
    Wektor2D(int wspx, int wspy) {
        x = wspx;
        y = wspy;
        num_wek++;
    }
    ~Wektor2D() { num_wek--; }
    void setX(int X) { x = X; }
    void setY(int Y) { y = Y; }
    int getX() { return x; }
    int getY() { return y; }
    void norm() {
        double  n = sqrt(x * x + y * y);
        cout << n << '\n';
    }
    void print() {
        cout << "x = " << x << '\n';
        cout << "y = " << y << '\n';
    }
    Wektor2D operator+(const Wektor2D& other) {
        return Wektor2D(x + other.x, y + other.y);
    }
    Wektor2D operator*(const Wektor2D& other) {
        return Wektor2D(x * other.x, y * other.y);
    }
    friend ostream& operator<<(ostream& os, const Wektor2D& other);

private:
    int num_wek{ 0 };
    int x;
    int y;
};

ostream& operator<<(ostream& os, const Wektor2D& other)
{
    os << other.x << ", " << other.y;
    return os;
}
