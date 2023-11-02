#include "Input.hpp"

#include "Input\\Keyboard.hpp"
#include "Input\\Mouse.hpp"

namespace NBCG
{
    void CInput::PInitialize()
    {
        NInput::GMouse.PInitialize();
    }

    void CInput::PUpdate()
    {
        SDL_Event LEvent;
        while(SDL_PollEvent(&LEvent))
        {
            switch(LEvent.type)
            {
                case SDL_KEYDOWN:
                    NInput::GKeyboard.PUpdate(LEvent);
                break;
                case SDL_KEYUP:
                    NInput::GKeyboard.PUpdate(LEvent);
                break;
                case SDL_MOUSEMOTION:
                    NInput::GMouse.PUpdate(LEvent);
                break;
                case SDL_MOUSEBUTTONDOWN:
                    NInput::GMouse.PUpdate(LEvent);
                break;
                case SDL_MOUSEBUTTONUP:
                    NInput::GMouse.PUpdate(LEvent);
                break;
                case SDL_MOUSEWHEEL:
                    NInput::GMouse.PUpdate(LEvent);
                break;
            }
        }
    }
}