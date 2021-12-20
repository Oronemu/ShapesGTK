#pragma once

namespace Figures {

    class Figure2D {
    public:
        virtual Figure2D* Clone() = 0;
        virtual double CalcArea() = 0;
        virtual double CalcPerimeter() = 0;
    };


    class Circle : public Figure2D {
        double r;
    public:
        Circle(double);
        virtual Figure2D* Clone();
        virtual double CalcArea();
        virtual double CalcPerimeter();

        double GetR();
    };

    class Rectangle : public Figure2D {
        double a, b;
    public:
        Rectangle(double, double);
        virtual Figure2D* Clone();
        virtual double CalcArea();
        virtual double CalcPerimeter();

        double GetA();
        double GetB();
    };

};