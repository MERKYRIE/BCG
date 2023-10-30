#pragma once

#include "Core.hpp"

namespace NBCG::Input::Mouse
{
    inline signed int PressedX[6];
    inline signed int PressedY[6];
    inline signed int ReleasedX[6];
    inline signed int ReleasedY[6];

    void Initialize();
    void Update(const SDL_Event& Event);
}