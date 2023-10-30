#pragma comment(lib , "opengl32.lib")
#pragma comment(lib , "glu32.lib")
#pragma comment(lib , "..\\glew\\glew32.lib")
#pragma comment(lib , "..\\sdl\\sdl2.lib")
#pragma comment(lib , "..\\sdl\\sdl2main.lib")
#pragma comment(lib , "..\\sdl\\sdl2_image.lib")
#pragma comment(lib , "..\\assimp\\assimp-vc143-mt.lib")

#include "Core.hpp"

#include "Input\\Keyboard.hpp"

signed int main(signed int , char**)
{
    //NBCG::CModel LModel{"\\Gordon.obj"};
    //glTranslated(0.0 , -1.0 , -3.0);
    NBCG::GShaderProgram.MUniform("UColor" , 0.0f , 0.5f , 0.5f , 1.0f);
    while(!NBCG::Input::Keyboard::Held[SDL_SCANCODE_ESCAPE])
    {
        NBCG::GVideo.MBegin();
        NBCG::GTime.MUpdate();
        NBCG::GInput.MUpdate();
        //LModel.MRender(0.0 , 0.0 , 0.0);
        //glRotated(0.05 , 0.0 , 1.0 , 0.0);
        glDrawElements(GL_TRIANGLES , 3 , GL_UNSIGNED_INT , nullptr);
        NBCG::GVideo.MEnd();
    };
    return 0;
}