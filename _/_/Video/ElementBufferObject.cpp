#include "ElementBufferObject.hpp"

#include "Debug.hpp"

namespace NBCG::NVideo
{
    void CElementBufferObject::PInitialize()
    {
        glGenBuffers(1 , &FIdentifier);
        GDebug.POGL();
    }

    CElementBufferObject& CElementBufferObject::PBind()
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER , FIdentifier);
        return *this;
    }

    CElementBufferObject& CElementBufferObject::PBuffer()
    {
        static unsigned int LIndices[]
        {
	           0 , 1 , 2
        };
        glBufferData(GL_ELEMENT_ARRAY_BUFFER , sizeof(LIndices) , LIndices , GL_STATIC_DRAW);
        return *this;
    }
}