#pragma once

#include "Core.hpp"

namespace NBCG
{
    inline class CVideo
    {
        private:
            friend class CCore;
        private:
            SDL_Window* FWindow;
            SDL_GLContext FContext;
        private:
            void PInitialize();
            void PBegin();
            void PEnd();
            void PDeinitialize();
        public:
            CVideo& DrawArrays();
            CVideo& DrawElements();
    }
    GVideo;
}