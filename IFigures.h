// Интерфейс фигур
// Все формы реализуют метод рисования, в котором логика рисования сохраняется

#include "Functions.h"
#include "Figures.h"

class IFigures {
public:
    virtual ~IFigures() = default;

    virtual void Draw(const Cairo::RefPtr<Cairo::Context>& pContext) = 0;
};

class IRectangle : public IFigures {
public:
    IRectangle(double pLeft, double pUp, double pWidth, double pHeight): mLeft{pLeft}, mUp{pUp}, mWidth{pWidth}, mHeight{pHeight} {

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


// class DrawableCircle : public DrawableShape2D {
//     Shapes::Circle c;
// public:
//     const unsigned int ID;
//     DrawableCircle(Shapes::Circle a) : c(a.GetR()), ID(ID_counter++) {
//         c = a;
//     }
//     virtual void Draw(wxDC& dc) {
//         //wxLogMessage("drawing circle, id: %d, coords: %f, %f", ID, coords.x, coords.y);
//         dc.DrawCircle(coords.x, coords.y, c.GetR() * 10);
//     }
//     virtual std::string GetIDTypeString();
//     virtual std::string GetFullInfoString();
//     virtual wxRect GetHitArea();
// };


class ICircle : public IFigures {
    Figures::Circle c;
public:    
    ICircle(Figures::Circle a, double pcX, double pcY): c(a.GetR()), mcX{pcX}, mcY{pcY}{
        c = a;
    }

    void Draw(const Cairo::RefPtr<Cairo::Context>& pContext) override {
        DrawCircle(pContext, mcX, mcY, c.GetR());
    }

private:
    double mcX;
    double mcY;
};

class ITriangle : public IFigures {
public:    
    ITriangle(double ptX1, double ptY1, double ptX2, double ptY2): mtX1{ptX1}, mtY1{ptY1}, mtX2{ptX2}, mtY2{ptY2}{

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

class IRing : public IFigures {
public:    
    IRing(double pcX, double pcY, double pRadius): mcX{pcX}, mcY{pcY}, mRadius{pRadius}{

    }

    void Draw(const Cairo::RefPtr<Cairo::Context>& pContext) override {
        DrawRing(pContext, mcX, mcY, mRadius);
    }

private:
    double mcX;
    double mcY;
    double mRadius;
};