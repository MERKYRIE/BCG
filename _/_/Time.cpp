#include "Time.hpp"

namespace NBCG
{
    void CTime::PUpdate()
    {
        FLast = FAbsolute;
        FAbsolute = SDL_GetTicks64();
        FRelative = FAbsolute - FLast;
    }
}