#pragma once

#include "Core.hpp"

namespace NBCG::NVideo
{
    inline class CShaderProgram
    {
        private:
            friend class CVideo;
        private:
            unsigned int FIdentifier;
        private:
            void PInitialize();
            void PUpdate();
    }
    GShaderProgram;
}