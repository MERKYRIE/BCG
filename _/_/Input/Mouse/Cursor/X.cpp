#include "X.hpp"

namespace NBCG::NInput::NMouse::NCursor
{
    void CX::PUpdate(const SDL_Event& AEvent)
    {
        FAbsolute = AEvent.motion.x;
        FRelative = AEvent.motion.xrel;
        FChanged = FRelative;
    }
}