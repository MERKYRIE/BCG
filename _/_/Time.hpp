#pragma once

namespace NBCG
{
    inline class CTime
    {
        private:
            unsigned long long int PLast;
            unsigned long long int PAbsolute;
            unsigned long long int PRelative;
        public:
            void MUpdate();
    }
    GTime;
}