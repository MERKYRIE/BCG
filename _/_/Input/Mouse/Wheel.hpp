#pragma once

#include "Engine.hpp"

namespace NBCG::NInput::NMouse
{
    inline class CWheel
    {
        private:
            friend class CMouse;
        private:
            signed int FState;
            bool FChanged;
            bool FDown;
            bool FUp;
        private:
            void PUpdate(const SDL_Event& AEvent);
    }
    GWheel;
}