#include "Mouse.hpp"

#include "Mouse\\Button.hpp"
#include "Mouse\\Cursor.hpp"
#include "Mouse\\Wheel.hpp"

namespace NBCG::Input::Mouse
{
    void Initialize()
    {
        Cursor::Initialize();
    }

    void Update(const SDL_Event& Event)
    {
        switch(Event.type)
        {
            case SDL_MOUSEMOTION:
                Cursor::Update(Event);
            break;
            case SDL_MOUSEBUTTONDOWN:
                Button::Update(Event);
                PressedX[Event.button.button - 1] = Event.button.x;
                PressedY[Event.button.button - 1] = Event.button.y;
            break;
            case SDL_MOUSEBUTTONUP:
                Button::Update(Event);
                ReleasedX[Event.button.button - 1] = Event.button.x;
                ReleasedY[Event.button.button - 1] = Event.button.y;
            break;
            case SDL_MOUSEWHEEL:
                Wheel::Update(Event);
            break;
        }
    }
}