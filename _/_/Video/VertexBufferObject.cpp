#include "VertexBufferObject.hpp"

#include "Debug.hpp"

namespace NBCG::NVideo
{
    void CVertexBufferObject::PInitialize()
    {
        glGenBuffers(1 , &FIdentifier);
        GDebug.POGL();
    }

    CVertexBufferObject& CVertexBufferObject::PBind()
    {
        glBindBuffer(GL_ARRAY_BUFFER , FIdentifier);
        return *this;
    }

    CVertexBufferObject& CVertexBufferObject::PBuffer()
    {
        static float LVertices[]
        {
	           -0.5f , -0.5f , 0.0f ,
             0.5f , -0.5f , 0.0f ,
             0.0f ,  0.5f , 0.0f
        };
        glBufferData(GL_ARRAY_BUFFER , sizeof(LVertices) , LVertices , GL_STATIC_DRAW);
        return *this;
    }
}