#include <gtkmm.h>
#include <cairo/cairo.h>
#include "Functions.h"

constexpr double LINE_WIDTH = 5.0;

void DrawRectangle(const Cairo::RefPtr<Cairo::Context>& pContext, double pStartX, double pStartY, double pWidth, double pHeight) {
        pContext->save();

        pContext->set_line_width(LINE_WIDTH);
        pContext->set_source_rgba(0, 0, 1, 1);
        pContext->rectangle(pStartX, pStartY, pWidth, pHeight);
        pContext->stroke();

        pContext->restore();
}

void DrawCircle(const Cairo::RefPtr<Cairo::Context>& pContext, double pStartX, double pStartY, double pWidth) {
        pContext->save();

        pContext->set_line_width(LINE_WIDTH);
        pContext->set_source_rgba(0, 0, 1, 1);
        pContext->arc(pStartX, pStartY, pWidth, 0, 5 * M_PI);
        pContext->stroke();

        pContext->restore();
}