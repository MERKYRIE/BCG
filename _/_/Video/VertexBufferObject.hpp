#pragma once

#include "Core.hpp"

namespace NBCG::NVideo
{
    inline class CVertexBufferObject
    {
        private:
            friend class CVideo;
        private:
            unsigned int FIdentifier;
        private:
            void PInitialize();
        public:
            CVertexBufferObject& PBind();
            CVertexBufferObject& PBuffer();
            CVertexBufferObject& PBuffer(const std::vector<aiVector3D>& AVertices);
    }
    GVertexBufferObject;
}