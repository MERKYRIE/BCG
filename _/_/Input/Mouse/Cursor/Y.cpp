#include "Y.hpp"

namespace NBCG::NInput::NMouse::NCursor
{
    void CY::PUpdate(const SDL_Event& AEvent)
    {
        FAbsolute = AEvent.motion.y;
        FRelative = AEvent.motion.yrel;
        FChanged = FRelative;
    }
}