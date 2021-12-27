#pragma once

#include <gtkmm.h>
#include "DrawHelper.h"

class MyWindow : public Gtk::Window {

public:
    MyWindow(): mDrawRectangleButton{"Квадрат"}, 
                mDrawCircleButton{"Круг"}, 
                mDrawTriangleButton("Треугольник"), 
                mDrawRingButton("Кольцо") {
        set_default_size(DEFAULT_WIDTH, DEFAULT_HEIGHT);

        mHeaderBar.set_show_close_button(true);
        mHeaderBar.pack_start(mDrawRectangleButton);
        mHeaderBar.pack_start(mDrawCircleButton);;
        mHeaderBar.pack_start(mDrawTriangleButton);;
        mHeaderBar.pack_start(mDrawRingButton);;

        set_titlebar(mHeaderBar);
        add(mDrawArea);

        mDrawRectangleButton.signal_clicked().connect([this](){RectangleButtonClicked();});
        mDrawCircleButton.signal_clicked().connect([this](){CircleButtonClicked();});
        mDrawTriangleButton.signal_clicked().connect([this](){TriangleButtonClicked();});
        mDrawRingButton.signal_clicked().connect([this](){RingButtonClicked();});

        show_all();
    }

    void showInfoDialog(string secondaryMessage) {
            Gtk::MessageDialog dialog("Информация", false, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_CANCEL);
            dialog.set_secondary_text(secondaryMessage);
            dialog.set_default_response(Gtk::RESPONSE_YES);
            dialog.run();
    }

private:

    Gtk::HeaderBar mHeaderBar;
    Gtk::Button mDrawRectangleButton;
    Gtk::Button mDrawCircleButton;
    Gtk::Button mDrawTriangleButton;
    Gtk::Button mDrawRingButton;
    DrawHelper mDrawArea;
    
    void RectangleButtonClicked(){
        mDrawArea.SetCurrentShape(DrawHelper::Figure::Rectangle);
    }

    void CircleButtonClicked(){
        mDrawArea.SetCurrentShape(DrawHelper::Figure::Circle);
    }

    void TriangleButtonClicked(){
        mDrawArea.SetCurrentShape(DrawHelper::Figure::Triangle);
    }

    void RingButtonClicked(){
        mDrawArea.SetCurrentShape(DrawHelper::Figure::Ring);
    }
};