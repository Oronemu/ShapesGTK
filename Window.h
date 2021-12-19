// Основное окно, которое содержит все виджеты(Кнопки и прочее). Через них пользователь выбирает фигуру для отрисовки.

#include <gtkmm.h>
#include "DrawHelper.h"

class MyWindow : public Gtk::Window {

public:
    MyWindow(): mDrawRectangleButton{"Квадрат"}, mDrawCircleButton{"Круг"} {
        set_default_size(DEFAULT_WIDTH, DEFAULT_HEIGHT);

        mHeaderBar.set_show_close_button(true);
        mHeaderBar.pack_start(mDrawRectangleButton);
        mHeaderBar.pack_start(mDrawCircleButton);;
        set_titlebar(mHeaderBar);
        add(mDrawArea);

        mDrawRectangleButton.signal_clicked().connect([this](){RectangleButtonClicked();});
        mDrawCircleButton.signal_clicked().connect([this](){CircleButtonClicked();});

        show_all();
    }

private:

    Gtk::HeaderBar mHeaderBar;
    Gtk::Button mDrawRectangleButton;
    Gtk::Button mDrawCircleButton;
    DrawHelper mDrawArea;

    void RectangleButtonClicked(){
        mDrawArea.SetCurrentShape(DrawHelper::Figure::Rectangle);
    }

    void CircleButtonClicked(){
        mDrawArea.SetCurrentShape(DrawHelper::Figure::Circle);
    }

};