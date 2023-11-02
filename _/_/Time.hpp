#pragma once

#include "Core.hpp"

namespace NBCG
{
    inline class CTime
    {
        private:
            friend class CCore;
        private:
            unsigned long long int FLast;
            unsigned long long int FAbsolute;
            unsigned long long int FRelative;
        private:
            void PUpdate();
    }
    GTime;
}