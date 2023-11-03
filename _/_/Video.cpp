#include "Video.hpp"

#include "Debug.hpp"
#include "Video\\ShaderProgram.hpp"
#include "Video\\VAO.hpp"

namespace NBCG
{
    void CVideo::PInitialize()
    {
        GDebug.PCode(SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION , 4));
        GDebug.PCode(SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION , 6));
        GDebug.PCode(SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS , 1));
        GDebug.PCode(SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES , 8));
        GDebug.PHandle(FWindow = SDL_CreateWindow("BCG" , 0 , 0 , 0 , 0 , SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_OPENGL));
        GDebug.PHandle(FContext = SDL_GL_CreateContext(FWindow));
        if(GDebug.PWarning(SDL_GL_SetSwapInterval(0) < 0))
        {
            if(GDebug.PWarning(SDL_GL_SetSwapInterval(1) < 0))
            {
                GDebug.PWarning(SDL_GL_SetSwapInterval(-1) < 0);
            }
        }
        SDL_DisplayMode LMode;
        SDL_GetWindowDisplayMode(FWindow , &LMode);
        FWidth = LMode.w;
        FHeight = LMode.h;
        FRatio = static_cast<float>(FWidth) / static_cast<float>(FHeight);
        FInversedRatio = static_cast<float>(FHeight) / static_cast<float>(FWidth);
        for(signed int LMultiplier{2} ; LMultiplier <= 100 ; LMultiplier++)
        {
            if(std::abs(FRatio * LMultiplier - std::round(FRatio * LMultiplier)) <= 0.1F)
            {
                FProportionalWidth = static_cast<signed int>(std::round(FRatio * LMultiplier));
                FProportionalHeight = LMultiplier;
                break;
            }
        }
        GDebug.PFlags(IMG_Init(IMG_INIT_PNG));
        glewInit();
        glEnable(GL_MULTISAMPLE);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA , GL_ONE_MINUS_SRC_ALPHA);
        GDebug.POGL();
        NVideo::GShaderProgram.PInitialize();
        NVideo::GVAO.PInitialize();
    }

    void CVideo::PBegin()
    {
        glClearColor(0.0F , 0.0F , 0.0F , 1.0F);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        NVideo::GShaderProgram.PUpdate();
    }

    void CVideo::PEnd()
    {
        SDL_GL_SwapWindow(FWindow);
    }

    void CVideo::PDeinitialize()
    {
        IMG_Quit();
        SDL_GL_DeleteContext(FContext);
        SDL_DestroyWindow(FWindow);
    }

    signed int CVideo::PWidth()
    {
        return FWidth;
    }

    signed int CVideo::PHeight()
    {
        return FHeight;
    }

    float CVideo::PRatio()
    {
        return FRatio;
    }

    float CVideo::PInversedRatio()
    {
        return FInversedRatio;
    }

    signed int CVideo::PProportionalWidth()
    {
        return FProportionalWidth;
    }

    signed int CVideo::PProportionalHeight()
    {
        return FProportionalHeight;
    }
}