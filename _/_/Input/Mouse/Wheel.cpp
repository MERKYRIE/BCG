#include "Wheel.hpp"

namespace NBCG::NInput::NMouse
{
    void CWheel::PUpdate(const SDL_Event& AEvent)
    {
        switch(AEvent.wheel.y)
        {
            case -1:
                FState = AEvent.wheel.y;
                FChanged = true;
                FDown = true;
                FUp = false;
            break;
            case 0:
                FState = AEvent.wheel.y;
                FChanged = false;
                FDown = false;
                FUp = false;
            break;
            case +1:
                FState = AEvent.wheel.y;
                FChanged = true;
                FDown = false;
                FUp = true;
            break;
        }
    }
}