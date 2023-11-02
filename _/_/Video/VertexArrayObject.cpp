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
        glVertexAttribPointer(0 , 3 , GL_FLOAT , GL_FALSE , 3 * sizeof(float) , nullptr);
        glEnableVertexAttribArray(0);
        GDebug.POGL();
    }
}