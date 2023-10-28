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
    static int num_wek;
    Informer inf;
    Wektor2D() { x = 0; y = 0; };
    Wektor2D(double wspx, double wspy) {
        x = wspx;
        y = wspy;
        num_wek++;
    }
    ~Wektor2D() { num_wek--; }
    void setX(double X) { x = X; }
    void setY(double Y) { y = Y; }
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
    friend ostream& operator<<(ostream& os, const Wektor2D& other);
    static int populacja() {
        return num_wek;
    }
    double operator*(const Wektor2D& other) {
        return x * other.x + y * other.y;
    }


private:

    double x;
    double y;
};

int Wektor2D::num_wek = 0;

ostream& operator<<(ostream& os, const Wektor2D& other)
{
    os << other.x << ", " << other.y;
    return os;
}
