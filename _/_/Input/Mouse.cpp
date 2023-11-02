#include "Mouse.hpp"

#include "Mouse\\Button.hpp"
#include "Mouse\\Cursor.hpp"
#include "Mouse\\Wheel.hpp"

namespace NBCG::NInput
{
    void CMouse::PInitialize()
    {
        NMouse::GCursor.PInitialize();
    }

    void CMouse::PUpdate(const SDL_Event& AEvent)
    {
        switch(AEvent.type)
        {
            case SDL_MOUSEMOTION:
                NMouse::GCursor.PUpdate(AEvent);
            break;
            case SDL_MOUSEBUTTONDOWN:
                NMouse::GButton.PUpdate(AEvent);
                FPressedX[AEvent.button.button - 1] = AEvent.button.x;
                FPressedY[AEvent.button.button - 1] = AEvent.button.y;
            break;
            case SDL_MOUSEBUTTONUP:
                NMouse::GButton.PUpdate(AEvent);
                FReleasedX[AEvent.button.button - 1] = AEvent.button.x;
                FReleasedY[AEvent.button.button - 1] = AEvent.button.y;
            break;
            case SDL_MOUSEWHEEL:
                NMouse::GWheel.PUpdate(AEvent);
            break;
        }
    }
}