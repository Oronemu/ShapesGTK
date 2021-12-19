// Интерфейс фигур
// Все формы реализуют метод рисования, в котором логика рисования сохраняется


#include "Functions.h"

class IFigures {
public:
    virtual ~IFigures() = default;

    virtual void Draw(const Cairo::RefPtr<Cairo::Context>& pContext) = 0;
};

class Rectangle : public IFigures {
public:
    Rectangle(double pLeft, double pUp, double pWidth, double pHeight): mLeft{pLeft}, mUp{pUp}, mWidth{pWidth}, mHeight{pHeight} {

    }

    void Draw(const Cairo::RefPtr<Cairo::Context>& pContext) override {
        DrawRectangle(pContext, mLeft, mUp, mWidth, mHeight);
    }

private:
    double mUp;
    double mLeft;
    double mWidth;
    double mHeight;
};

class Circle : public IFigures {
public:    
    Circle(double pcX, double pcY, double pRadius): mcX{pcX}, mcY{pcY}, mRadius{pRadius}{

    }

    void Draw(const Cairo::RefPtr<Cairo::Context>& pContext) override {
        DrawCircle(pContext, mcX, mcY, mRadius);
    }

private:
    double mcX;
    double mcY;
    double mRadius;
};

class Triangle : public IFigures {
public:    
    Triangle(double ptX1, double ptY1, double ptX2, double ptY2): mtX1{ptX1}, mtY1{ptY1}, mtX2{ptX2}, mtY2{ptY2}{

    }

    void Draw(const Cairo::RefPtr<Cairo::Context>& pContext) override {
        DrawTriangle(pContext, mtX1, mtY1, mtX2, mtY2);
    }

private:
    double mtX1;
    double mtY1;
    double mtX2;
    double mtY2;
};

class Ring : public IFigures {
public:    
    Ring(double pcX, double pcY, double pRadius): mcX{pcX}, mcY{pcY}, mRadius{pRadius}{

    }

    void Draw(const Cairo::RefPtr<Cairo::Context>& pContext) override {
        DrawRing(pContext, mcX, mcY, mRadius);
    }

private:
    double mcX;
    double mcY;
    double mRadius;
};