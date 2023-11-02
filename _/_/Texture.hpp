#pragma once

#include "Core.hpp"

namespace NBCG
{
    class CTexture
    {
        private:
            unsigned int FIdentifier;
        public:
            CTexture(const std::string& APath);
            void PBind() const;
    };
}