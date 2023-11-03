#pragma once

#include "Engine.hpp"

namespace NBCG::NInput::NMouse
{
    inline class CButton
    {
        private:
            friend class CMouse;
        private:    
            bool FHeld[6];
            bool FPressed[6];
            bool FReleased[6];
        private:    
            void PUpdate(const SDL_Event& AEvent);
    }
    GButton;
}