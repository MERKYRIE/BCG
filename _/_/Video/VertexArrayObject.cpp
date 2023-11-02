#include "VertexArrayObject.hpp"

#include "ElementBufferObject.hpp"
#include "VertexBufferObject.hpp"

#include "Debug.hpp"

namespace NBCG::NVideo
{
    void CVertexArrayObject::PInitialize()
    {
        glGenVertexArrays(1 , &FIdentifier);  
        glBindVertexArray(FIdentifier);
        GVertexBufferObject.PBind().PBuffer();
        GElementBufferObject.PBind().PBuffer();
        glVertexAttribPointer(0 , 3 , GL_FLOAT , GL_FALSE , 6 * sizeof(float) , reinterpret_cast<void*>(0 * sizeof(float)));
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1 , 3 , GL_FLOAT , GL_FALSE , 6 * sizeof(float) , reinterpret_cast<void*>(3 * sizeof(float)));
        glEnableVertexAttribArray(1);
        GDebug.POGL();
    }
}