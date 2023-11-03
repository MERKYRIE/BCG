#pragma once

#include "Engine.hpp"

namespace NBCG
{
    inline class CInput
    {
        private:
            friend class CEngine;
        private:
            void PInitialize();
            void PUpdate();
    }
    GInput;
}