#pragma once

#include "Core.hpp"

#include "Texture.hpp"

namespace NBCG
{
    class CMaterial
    {
        private:
            std::unique_ptr<CTexture> FTexture;
        public:
            CMaterial(const aiMaterial* AMaterial);
            void PBind() const;
    };
}