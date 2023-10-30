#include "Core.hpp"

namespace NBCG
{
    CElementBufferObject::CElementBufferObject()
    {
        glGenBuffers(1 , &PIdentifier);
        GDebug.MOGL();
    }

    CElementBufferObject& CElementBufferObject::MBind()
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER , PIdentifier);
        return *this;
    }

    CElementBufferObject& CElementBufferObject::MBuffer()
    {
        static unsigned int LIndices[]
        {
	           0 , 1 , 2
        };
        glBufferData(GL_ELEMENT_ARRAY_BUFFER , sizeof(LIndices) , LIndices , GL_STATIC_DRAW);
        return *this;
    }
}