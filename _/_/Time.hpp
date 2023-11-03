#pragma once

#include "Engine.hpp"

namespace NBCG
{
    inline class CTime
    {
        private:
            friend class CEngine;
        private:
            unsigned int FLast;
            unsigned int FAbsolute;
            unsigned int FRelative;
        private:
            void PUpdate();
        public:
            unsigned int PAbsolute();
            unsigned int PRelative();
    }
    GTime;
}