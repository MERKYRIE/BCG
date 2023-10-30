#include "Keyboard.hpp"

namespace NBCG::Input::Keyboard
{
    void Update(const SDL_Event& Event)
    {
        switch(Event.type)
        {
            case SDL_KEYDOWN:
                Held[Event.key.keysym.scancode] = true;
                if(!Event.key.repeat)
                {
                    Pressed[Event.key.keysym.scancode] = true;
                }
                Released[Event.key.keysym.scancode] = false;
            break;
            case SDL_KEYUP:
                Held[Event.key.keysym.scancode] = false;
                Pressed[Event.key.keysym.scancode] = false;
                if(!Event.key.repeat)
                {
                    Released[Event.key.keysym.scancode] = true;
                }
            break;
        }
    }
}