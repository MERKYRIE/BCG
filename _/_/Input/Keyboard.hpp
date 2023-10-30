#pragma once

#include "Core.hpp"

namespace NBCG::Input::Keyboard
{
    inline unsigned char Held[291];
    inline unsigned char Pressed[291];
    inline unsigned char Released[291];
    
    void Update(const SDL_Event& Event);
}