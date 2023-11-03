#pragma once

#include "Engine.hpp"

namespace NBCG::NInput::NMouse
{
    inline class CCursor
    {
        private:
            friend class CMouse;
        private:    
            void PInitialize();
            void PUpdate(const SDL_Event& AEvent);
    }
    GCursor;
}