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
    }
    GVertexArrayObject;
}