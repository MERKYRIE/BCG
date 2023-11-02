#pragma once

#include "Core.hpp"

namespace NBCG::NVideo
{
    inline class CVertexArrayObject
    {
        private:
            friend class CVideo;
        private:
            unsigned int FIdentifier;
        private:
            void PInitialize();
        public:
            CVertexArrayObject& PBind();
            CVertexArrayObject& PBuffer();
            CVertexArrayObject& PBuffer(const std::vector<aiVector3D>& AVertices , const std::vector<unsigned int>& AIndices);
    }
    GVertexArrayObject;
}