#include "Core.hpp"

namespace NBCG
{
    CVertexArrayBuffer::CVertexArrayBuffer()
    {
        glGenVertexArrays(1 , &PIdentifier);  
        glBindVertexArray(PIdentifier);
        GVertexBufferObject.MBind().MBuffer();
        GElementBufferObject.MBind().MBuffer();
        glVertexAttribPointer(0 , 3 , GL_FLOAT , GL_FALSE , 3 * sizeof(float) , nullptr);
        glEnableVertexAttribArray(0);
        GDebug.MOGL();
    }
}