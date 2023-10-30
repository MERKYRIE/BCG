#pragma once

namespace NBCG
{
    class CTexture
    {
        private:
            unsigned int PIdentifier;
        public:
            CTexture(const std::string& APath);
            void MBind() const;
    };
}