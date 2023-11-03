#pragma once

#include "Engine.hpp"

namespace NBCG
{
    inline class CVideo
    {
        private:
            friend class CEngine;
        private:
            SDL_Window* FWindow;
            SDL_GLContext FContext;
            signed int FWidth;
            signed int FHeight;
            float FRatio;
            float FInversedRatio;
            signed int FProportionalWidth;
            signed int FProportionalHeight;
        private:
            void PInitialize();
            void PBegin();
            void PEnd();
            void PDeinitialize();
        public:
            signed int PWidth();
            signed int PHeight();
            float PRatio();
            float PInversedRatio();
            signed int PProportionalWidth();
            signed int PProportionalHeight();
    }
    GVideo;
}