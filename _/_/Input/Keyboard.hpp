#pragma once

#include "Engine.hpp"

namespace NBCG::NInput
{
    inline class CKeyboard
    {
        private:
            friend class CInput;
        private:    
            unsigned char FHeld[291];
            unsigned char FPressed[291];
            unsigned char FReleased[291];
        private:    
            void PUpdate(const SDL_Event& AEvent);
        public:
            bool PHeld(unsigned short AKey);
            bool PPressed(unsigned short AKey);
            bool PReleased(unsigned short AKey);
    }
    GKeyboard;
}