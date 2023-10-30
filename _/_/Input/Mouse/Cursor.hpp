#pragma once

#include "Core.hpp"

namespace NBCG::Input::Mouse::Cursor
{
    void Initialize();
    void Update(const SDL_Event& Event);
}