#pragma comment(lib , "..\\glew\\glew32.lib")
#pragma comment(lib , "..\\sdl\\sdl2.lib")
#pragma comment(lib , "..\\sdl\\sdl2main.lib")
#pragma comment(lib , "..\\sdl\\sdl2_image.lib")
#pragma comment(lib , "..\\assimp\\assimp-vc143-mt.lib")
#pragma comment(lib , "opengl32.lib")
#pragma comment(lib , "glu32.lib")

#include "Core.hpp"

#include "Debug.hpp"
#include "Input.hpp"
#include "Input\\Keyboard.hpp"
#include "Time.hpp"
#include "Video.hpp"
#include "Video\\ShaderProgram.hpp"

namespace NBCG
{
    CCore::CCore()
    {
        GDebug.PCode(SDL_Init(SDL_INIT_EVERYTHING));
        GVideo.PInitialize();
        GInput.PInitialize();
    }
    
    void CCore::PUpdate()
    {
        //CModel LModel{"\\Gordon.obj"};
        //glTranslated(0.0 , -1.0 , -3.0);
        NVideo::GShaderProgram.PUniform("UColor" , 0.0F , 0.5F , 0.5F , 1.0F);
        while(!NInput::GKeyboard.PHeld(SDL_SCANCODE_ESCAPE))
        {
            GVideo.PBegin();
            GInput.PUpdate();
            GTime.PUpdate();
            //LModel.MRender(0.0 , 0.0 , 0.0);
            //glRotated(0.05 , 0.0 , 1.0 , 0.0);
            glDrawElements(GL_TRIANGLES , 3 , GL_UNSIGNED_INT , nullptr);
            GVideo.PEnd();
        }
    }
    
    CCore::~CCore()
    {
        GVideo.PDeinitialize();
        SDL_Quit();
    }
}

signed int main(signed int , char**)
{
    NBCG::GCore.PUpdate();
    return 0;
}