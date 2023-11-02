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
        glVertexAttribPointer(0 , 3 , GL_FLOAT , GL_FALSE , 3 * sizeof(float) , reinterpret_cast<void*>(0 * sizeof(float)));
        glEnableVertexAttribArray(0);
        GDebug.POGL();
    }

    CVertexArrayObject& CVertexArrayObject::PBind()
    {
        GVertexBufferObject.PBind();
        GElementBufferObject.PBind();
        return *this;
    }

    CVertexArrayObject& CVertexArrayObject::PBuffer()
    {
        GVertexBufferObject.PBuffer();
        GElementBufferObject.PBuffer();
        return *this;
    }

    CVertexArrayObject& CVertexArrayObject::PBuffer(const std::vector<aiVector3D>& AVertices , const std::vector<unsigned int>& AIndices)
    {
        GVertexBufferObject.PBuffer(AVertices);
        GElementBufferObject.PBuffer(AIndices);
        return *this;
    }
}