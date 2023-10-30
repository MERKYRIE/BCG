#pragma once

#include "Core.hpp"

namespace NBCG::Input::Mouse::Cursor::Y
{
    inline signed int Absolute;
    inline signed int Relative;
    inline bool Changed;

    void Update(const SDL_Event& Event);
}