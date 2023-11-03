#pragma once

#include "Engine.hpp"

namespace NBCG::NInput::NMouse::NCursor
{
    inline class CX
    {
        private:
            friend class CCursor;
        private:
            signed int FAbsolute;
            signed int FRelative;
            bool FChanged;
        private:
            void PUpdate(const SDL_Event& AEvent);
    }
    GX;
}