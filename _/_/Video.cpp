#include "Core.hpp"

namespace NBCG
{
    CVideo::CVideo()
    {
        GDebug.MCode(SDL_Init(SDL_INIT_VIDEO));
        GDebug.MCode(SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION , 4));
        GDebug.MCode(SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION , 6));
        GDebug.MCode(SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS , 1));
        GDebug.MCode(SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES , 8));
        GDebug.MHandle(PWindow = SDL_CreateWindow("MRKOGL" , 0 , 0 , 0 , 0 , SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_OPENGL));
        GDebug.MHandle(PContext = SDL_GL_CreateContext(PWindow));
        if(GDebug.MWarning(SDL_GL_SetSwapInterval(0) < 0))
        {
            if(GDebug.MWarning(SDL_GL_SetSwapInterval(1) < 0))
            {
                GDebug.MWarning(SDL_GL_SetSwapInterval(-1) < 0);
            }
        }
        GDebug.MFlags(IMG_Init(IMG_INIT_PNG));
        glewInit();
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
        /*
        glEnable(GL_MULTISAMPLE);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA , GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_DEPTH_TEST);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(90.0 , 16.0 / 9.0 , 0.1 , 1000.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        */
        GDebug.MOGL();
    }

    void CVideo::MBegin()
    {
        glColor4ub(255 , 255 , 255 , 255);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void CVideo::MEnd()
    {
        SDL_GL_SwapWindow(PWindow);
    }

    CVideo::~CVideo()
    {
        IMG_Quit();
        SDL_GL_DeleteContext(PContext);
        SDL_DestroyWindow(PWindow);
        SDL_Quit();
    }
}