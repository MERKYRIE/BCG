#pragma comment(lib , "..\\glew\\glew32.lib")
#pragma comment(lib , "..\\sdl\\sdl2.lib")
#pragma comment(lib , "..\\sdl\\sdl2main.lib")
#pragma comment(lib , "..\\sdl\\sdl2_image.lib")
#pragma comment(lib , "opengl32.lib")
#pragma comment(lib , "glu32.lib")

#include "Engine.hpp"

#include "Debug.hpp"
#include "Game.hpp"
#include "Input.hpp"
#include "Input\\Keyboard.hpp"
#include "Time.hpp"
#include "Video.hpp"
#include "Video\\ShaderProgram.hpp"

namespace NBCG
{
    void CEngine::PInitialize()
    {
        GGame.PInitialize();
    }
    
    void CEngine::PInitiate()
    {
        while(!NInput::GKeyboard.PHeld(SDL_SCANCODE_ESCAPE))
        {
            GVideo.PBegin();
            GInput.PUpdate();
            GTime.PUpdate();
            GGame.PUpdate();
            GVideo.PEnd();
        }
    }

    CEngine::CEngine()
    {
        GDebug.PCode(SDL_Init(SDL_INIT_EVERYTHING));
        GInput.PInitialize();
        GVideo.PInitialize();
    }
    
    CEngine::~CEngine()
    {
        GVideo.PDeinitialize();
        SDL_Quit();
    }
}

signed int main(signed int , char**)
{
    NBCG::GEngine.PInitialize();
    NBCG::GEngine.PInitiate();
    return 0;
}