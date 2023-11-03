#include "VAO.hpp"

#include "VAO\\VBO.hpp"
#include "VAO\\EBO.hpp"

#include "Debug.hpp"

namespace NBCG::NVideo
{
    void CVAO::PInitialize()
    {
        glGenVertexArrays(1 , &FIdentifier);  
        glBindVertexArray(FIdentifier);
        GVBO.PInitialize();
        GEBO.PInitialize();
        glVertexAttribPointer(0 , 2 , GL_FLOAT , GL_FALSE , 2 * sizeof(float) , reinterpret_cast<void*>(0 * sizeof(float)));
        glEnableVertexAttribArray(0);
        GDebug.POGL();
    }
}