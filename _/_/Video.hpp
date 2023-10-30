#pragma once

namespace NBCG
{
    inline class CVideo
    {
        private:
            SDL_Window* PWindow;
            SDL_GLContext PContext;
        public:
            CVideo();
            void MBegin();
            void MEnd();
            ~CVideo();
    }
    GVideo;
}