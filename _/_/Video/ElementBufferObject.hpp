#pragma once

#include "Core.hpp"

namespace NBCG::NVideo
{
    inline class CElementBufferObject
    {
        private:
            friend class CVideo;
        private:
            unsigned int FIdentifier;
        private:
            void PInitialize();
        public:
            CElementBufferObject& PBind();
            CElementBufferObject& PBuffer();
            CElementBufferObject& PBuffer(const std::vector<unsigned int>& AIndices);
    }
    GElementBufferObject;
}