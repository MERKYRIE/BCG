#include "Button.hpp"

namespace NBCG::Input::Mouse::Button
{
    void Update(const SDL_Event& Event)
    {
        switch(Event.type)
        {
            case SDL_MOUSEBUTTONDOWN:
                Held[Event.button.button - 1] = true;
                Pressed[Event.button.button - 1] = true;
                Released[Event.button.button - 1] = false;
            break;
            case SDL_MOUSEBUTTONUP:
                Held[Event.button.button - 1] = false;
                Pressed[Event.button.button - 1] = false;
                Released[Event.button.button - 1] = true;
            break;
        }
    }
}