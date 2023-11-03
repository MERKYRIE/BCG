#include "VBO.hpp"

#include "Debug.hpp"

namespace NBCG::NVideo
{
    void CVBO::PInitialize()
    {
        glGenBuffers(1 , &FIdentifier);
        glBindBuffer(GL_ARRAY_BUFFER , FIdentifier);
        GDebug.POGL();
    }

    CVBO& CVBO::PBuffer(const std::vector<std::array<float , 2>>& AVertices)
    {
        glBufferData(GL_ARRAY_BUFFER , AVertices.size() * sizeof(std::array<float , 2>) , AVertices.data() , GL_STATIC_DRAW);
        return *this;
    }
}