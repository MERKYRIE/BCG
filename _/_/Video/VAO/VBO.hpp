#pragma once

#include "Engine.hpp"

namespace NBCG::NVideo
{
    inline class CVBO
    {
        private:
            friend class CVAO;
        private:
            unsigned int FIdentifier;
        private:
            void PInitialize();
        public:
            CVBO& PBuffer(const std::vector<std::array<float , 2>>& AVertices);
    }
    GVBO;
}