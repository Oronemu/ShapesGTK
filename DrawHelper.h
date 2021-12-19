// Этот класс представляет из себя виджет, на котором можно рисовать
// Это область Gtk::Drawing с определенными обработчиками сигналов,
// чтобы рисовать фигуры по действиям пользователя

// Вся отрисовка происходит в методе onDraw, а все обработчики сигналов для корректной работы
// обрабатывают данные (позиция и прочая фигня) для onDraw метода

#include <gtkmm.h>
#include "Functions.h"
#include "IFigures.h"

constexpr int DEFAULT_WIDTH = 500;
constexpr int DEFAULT_HEIGHT = 500;

class DrawHelper : public Gtk::DrawingArea {
    public:
        enum class Figure {
            None,
            Rectangle,
            Circle,
        };

        DrawHelper() {
            add_events(Gdk::BUTTON1_MOTION_MASK | Gdk::BUTTON_PRESS_MASK | Gdk::BUTTON_RELEASE_MASK);

            // Обработчики сигналов нажатия, перетаскивания и отпускания:
            signal_button_press_event().connect([this](GdkEventButton* pEvent){return OnButtonPressed(pEvent);});
            signal_motion_notify_event().connect([this](GdkEventMotion* pEvent){return OnMouseMotion(pEvent);});
            signal_button_release_event().connect([this](GdkEventButton* pEvent){return OnButtonReleased(pEvent);});
        }

        void SetCurrentShape(Figure pFigure) {
            mCurrentFigure = pFigure;
        }

    private:
        std::vector<std::unique_ptr<IFigures>> mAlreadyDrawn;

        // Вся отрисовка фигур происходит здесь:
        bool on_draw(const Cairo::RefPtr<Cairo::Context>& pContext) override {

            if(!mBuffer){
                mBuffer = Gdk::Pixbuf::create(Gdk::COLORSPACE_RGB,1,8,DEFAULT_WIDTH,DEFAULT_HEIGHT);
            }

            Gdk::Cairo::set_source_pixbuf(pContext, mBuffer, 0, 0);
            pContext->paint();

            for(const auto& figure : mAlreadyDrawn) {
                figure->Draw(pContext);
            }

            if(mCurrentFigure == Figure::Rectangle) {
                DrawRectangle(pContext, mStartX, mStartY, mWidth, mHeight);
            }

            if(mCurrentFigure == Figure::Circle) {
                DrawCircle(pContext, mStartX, mStartY, mWidth);
            }
            return false;
        }

        bool OnButtonPressed(GdkEventButton* pEvent) {
            mStartX = pEvent->x;
            mStartY = pEvent->y;

            return true;
        }

        bool OnMouseMotion(GdkEventMotion* pEvent) {
            mEndX = pEvent->x;
            mEndY = pEvent->y;

            mWidth  = mEndX - mStartX;
            mHeight = mEndY - mStartY;

            queue_draw();

            return true;
        }

        bool OnButtonReleased(GdkEventButton* pEvent) {
            if(mCurrentFigure == Figure::Rectangle) {
                mAlreadyDrawn.push_back(std::make_unique<Rectangle>(mStartX, mStartY, mWidth, mHeight));
            }

            if(mCurrentFigure == Figure::Circle) {
                mAlreadyDrawn.push_back(std::make_unique<Circle>(mStartX, mStartY, mWidth));
            }
            return true;
        }

        Figure mCurrentFigure = Figure::None;
        Glib::RefPtr<Gdk::Pixbuf> mBuffer;

        double mStartX;
        double mStartY;

        double mEndX;
        double mEndY;

        double mWidth;
        double mHeight;
};