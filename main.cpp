﻿#include <gtkmm.h>
#include "Window.h"

int main(int argc, char *argv[]) {
    auto Application = Gtk::Application::create(argc, argv);
    MyWindow window;
    return Application->run(window);
}