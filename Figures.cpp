#include "Figures.h"
#include <math.h>
#include <string>

using namespace Figures;

Circle::Circle(double r) {
    this->r = r;
}

Figure2D* Circle::Clone() {
    Figure2D* f = new Circle(*this);
    return f;
}

double Circle::CalcArea() { return M_PI * r * r; }
double Circle::CalcPerimeter() { return 2 * M_PI * r; }
double Circle::GetR() { return r; }

//-----------------------------------------------------------------------------
Rectangle::Rectangle(double a, double b) {
    this->a = a;
    this->b = b;
}

Figure2D* Rectangle::Clone() {
    Figure2D* f = new Rectangle(*this);
    return f;
}

double Rectangle::CalcArea() { return a * b; }
double Rectangle::CalcPerimeter() { return (a + b) * 2; }
double Rectangle::GetA() { return a; }
double Rectangle::GetB() { return b; }
