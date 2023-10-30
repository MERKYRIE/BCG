#include "Core.hpp"

namespace NBCG
{
    CVertexBufferObject::CVertexBufferObject()
    {
        glGenBuffers(1 , &PIdentifier);
        GDebug.MOGL();
    }

    CVertexBufferObject& CVertexBufferObject::MBind()
    {
        glBindBuffer(GL_ARRAY_BUFFER , PIdentifier);
        return *this;
    }

    CVertexBufferObject& CVertexBufferObject::MBuffer()
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