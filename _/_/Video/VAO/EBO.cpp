#include "EBO.hpp"

#include "Debug.hpp"

namespace NBCG::NVideo
{
    void CEBO::PInitialize()
    {
        glGenBuffers(1 , &FIdentifier);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER , FIdentifier);
        GDebug.POGL();
    }

    CEBO& CEBO::PBuffer(const std::vector<unsigned int>& AIndices)
    {
        glBufferData(GL_ELEMENT_ARRAY_BUFFER , AIndices.size() * sizeof(unsigned int) , AIndices.data() , GL_STATIC_DRAW);
        return *this;
    }
}