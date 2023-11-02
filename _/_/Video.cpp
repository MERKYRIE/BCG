#include "Video.hpp"

#include "Debug.hpp"
#include "Model.hpp"
#include "Video\\ShaderProgram.hpp"
#include "Video\\VertexBufferObject.hpp"
#include "Video\\ElementBufferObject.hpp"
#include "Video\\VertexArrayObject.hpp"

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
        GDebug.PFlags(IMG_Init(IMG_INIT_PNG));
        glewInit();
        glEnable(GL_MULTISAMPLE);
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA , GL_ONE_MINUS_SRC_ALPHA);
        GDebug.POGL();
        NVideo::GShaderProgram.PInitialize();
        NVideo::GVertexBufferObject.PInitialize();
        NVideo::GElementBufferObject.PInitialize();
        NVideo::GVertexArrayObject.PInitialize();
    }

    void CVideo::PBegin()
    {
        glClearColor(0.0F , 0.0F , 0.0F , 1.0F);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        NVideo::GShaderProgram.PUpdate();
    }

    void CVideo::PEnd()
    {
        static CModel LModel{"\\Gordon.obj"};
        LModel.PRender(0.0 , 0.0 , 0.0);
        SDL_GL_SwapWindow(FWindow);
    }

    void CVideo::PDeinitialize()
    {
        IMG_Quit();
        SDL_GL_DeleteContext(FContext);
        SDL_DestroyWindow(FWindow);
    }
}