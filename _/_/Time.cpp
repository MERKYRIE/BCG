#include "Core.hpp"

namespace NBCG
{
    void CTime::MUpdate()
    {
        PLast = PAbsolute;
        PAbsolute = SDL_GetTicks64();
        PRelative = PAbsolute - PLast;
    }
}