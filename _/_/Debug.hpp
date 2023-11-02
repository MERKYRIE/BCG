#pragma once

#include "Core.hpp"

namespace NBCG
{
    inline class CDebug
    {
        public:
            void PError(bool ACondition = true , const std::source_location& ALocation = std::source_location::current());
            bool PWarning(bool ACondition = true , const std::source_location& ALocation = std::source_location::current());
            void PCode(signed int AValue , const std::source_location& ALocation = std::source_location::current());
            void PHandle(const void* APointer , const std::source_location& ALocation = std::source_location::current());
            void PFlags(signed int AValue , const std::source_location& ALocation = std::source_location::current());
            void POGL(const std::source_location& ALocation = std::source_location::current());
            void PAI(const void* AHandle , const std::source_location& ALocation = std::source_location::current());
    }
    GDebug;
}