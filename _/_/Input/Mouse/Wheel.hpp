#pragma once

#include "Core.hpp"

namespace NBCG::Input::Mouse::Wheel
{
    inline signed int State;
    inline bool Changed;
    inline bool Down;
    inline bool Up;

    void Update(const SDL_Event& Event);
}