#pragma once

namespace NBCG
{
    class CMaterial
    {
        private:
            std::unique_ptr<CTexture> PTexture;
        public:
            CMaterial(const aiMaterial* AMaterial);
            void MBind() const;
    };
}