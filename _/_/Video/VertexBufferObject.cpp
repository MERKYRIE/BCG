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
            -5.0F , -5.0F , -5.0F ,
             5.0F ,  5.0F ,  5.0F ,
            10.0F , 10.0F , -5.0F
        };
        glBufferData(GL_ARRAY_BUFFER , sizeof(LVertices) , LVertices , GL_STATIC_DRAW);
        return *this;
    }

    CVertexBufferObject& CVertexBufferObject::PBuffer(const std::vector<aiVector3D>& AVertices)
    {
        glBufferData(GL_ARRAY_BUFFER , AVertices.size() * sizeof(aiVector3D) , AVertices.data() , GL_STATIC_DRAW);
        return *this;
    }
}