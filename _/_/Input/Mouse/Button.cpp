#include "Button.hpp"

namespace NBCG::NInput::NMouse
{
    void CButton::PUpdate(const SDL_Event& AEvent)
    {
        switch(AEvent.type)
        {
            case SDL_MOUSEBUTTONDOWN:
                FHeld[AEvent.button.button - 1] = true;
                FPressed[AEvent.button.button - 1] = true;
                FReleased[AEvent.button.button - 1] = false;
            break;
            case SDL_MOUSEBUTTONUP:
                FHeld[AEvent.button.button - 1] = false;
                FPressed[AEvent.button.button - 1] = false;
                FReleased[AEvent.button.button - 1] = true;
            break;
        }
    }
}