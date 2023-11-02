#pragma once

#include "Core.hpp"

namespace NBCG::NInput
{
    inline class CMouse
    {
        private:
            friend class CInput;
        private:    
            signed int FPressedX[6];
            signed int FPressedY[6];
            signed int FReleasedX[6];
            signed int FReleasedY[6];
        private:    
            void PInitialize();
            void PUpdate(const SDL_Event& AEvent);
    }
    GMouse;
}