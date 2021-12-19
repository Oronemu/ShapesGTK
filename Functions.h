#include <gtkmm.h>
#include <cairo/cairo.h>

// Свободные функции для отрисовки фигур:
void DrawRectangle(const Cairo::RefPtr<Cairo::Context>& ,double, double, double, double);
void DrawCircle(const Cairo::RefPtr<Cairo::Context>&, double, double, double);
void DrawTriangle(const Cairo::RefPtr<Cairo::Context>&, double, double, double, double);
void DrawRing(const Cairo::RefPtr<Cairo::Context>&, double, double, double);