#include "Wheel.hpp"

namespace NBCG::Input::Mouse::Wheel
{
    void Update(const SDL_Event& Event)
    {
        switch(Event.wheel.y)
        {
            case -1:
                State = Event.wheel.y;
                Changed = true;
                Down = true;
                Up = false;
            break;
            case 0:
                State = Event.wheel.y;
                Changed = false;
                Down = false;
                Up = false;
            break;
            case +1:
                State = Event.wheel.y;
                Changed = true;
                Down = false;
                Up = true;
            break;
        }
    }
}