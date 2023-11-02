#pragma once

#include "Core.hpp"

namespace NBCG
{
    inline class CInput
    {
        private:
            friend class CCore;
        private:
            void PInitialize();
            void PUpdate();
    }
    GInput;
}