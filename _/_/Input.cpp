#include "Core.hpp"

#include "Input\\Keyboard.hpp"
#include "Input\\Mouse.hpp"

namespace NBCG
{
    CInput::CInput()
    {
        Input::Mouse::Initialize();
    }

    void CInput::MUpdate()
    {
        SDL_Event LEvent;
        while(SDL_PollEvent(&LEvent))
        {
            switch(LEvent.type)
            {
                case SDL_KEYDOWN:
                    Input::Keyboard::Update(LEvent);
                break;
                case SDL_KEYUP:
                    Input::Keyboard::Update(LEvent);
                break;
                case SDL_MOUSEMOTION:
                    Input::Mouse::Update(LEvent);
                break;
                case SDL_MOUSEBUTTONDOWN:
                    Input::Mouse::Update(LEvent);
                break;
                case SDL_MOUSEBUTTONUP:
                    Input::Mouse::Update(LEvent);
                break;
                case SDL_MOUSEWHEEL:
                    Input::Mouse::Update(LEvent);
                break;
            }
        }
    }
}