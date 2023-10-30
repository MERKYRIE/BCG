#pragma once

namespace NBCG
{
    inline class CDebug
    {
        public:
            void MError(bool ACondition = true , const std::source_location& ALocation = std::source_location::current());
            bool MWarning(bool ACondition = true , const std::source_location& ALocation = std::source_location::current());
            void MCode(signed int AValue , const std::source_location& ALocation = std::source_location::current());
            void MHandle(const void* APointer , const std::source_location& ALocation = std::source_location::current());
            void MFlags(signed int AValue , const std::source_location& ALocation = std::source_location::current());
            void MOGL(const std::source_location& ALocation = std::source_location::current());
            void MAI(const void* AHandle , const std::source_location& ALocation = std::source_location::current());
    }
    GDebug;
}