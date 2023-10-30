#pragma once

#include "Core.hpp"

namespace NBCG::Input::Mouse::Button
{
    inline bool Held[6];
    inline bool Pressed[6];
    inline bool Released[6];

    void Update(const SDL_Event& Event);
}