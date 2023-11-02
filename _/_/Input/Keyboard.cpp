#include "Keyboard.hpp"

namespace NBCG::NInput
{
    void CKeyboard::PUpdate(const SDL_Event& AEvent)
    {
        switch(AEvent.type)
        {
            case SDL_KEYDOWN:
                FHeld[AEvent.key.keysym.scancode] = true;
                if(!AEvent.key.repeat)
                {
                    FPressed[AEvent.key.keysym.scancode] = true;
                }
                FReleased[AEvent.key.keysym.scancode] = false;
            break;
            case SDL_KEYUP:
                FHeld[AEvent.key.keysym.scancode] = false;
                FPressed[AEvent.key.keysym.scancode] = false;
                if(!AEvent.key.repeat)
                {
                    FReleased[AEvent.key.keysym.scancode] = true;
                }
            break;
        }
    }

    bool CKeyboard::PHeld(unsigned short AKey)
    {
        return FHeld[AKey];
    }

    bool CKeyboard::PPressed(unsigned short AKey)
    {
        return FPressed[AKey];
    }

    bool CKeyboard::PReleased(unsigned short AKey)
    {
        return FReleased[AKey];
    }
}