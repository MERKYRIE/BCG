#pragma once

#include "Engine.hpp"

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
        public:
            CShaderProgram& PColor(const std::array<float , 4> AColor);
    }
    GShaderProgram;
}