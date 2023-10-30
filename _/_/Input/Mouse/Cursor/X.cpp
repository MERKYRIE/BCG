#include "X.hpp"

namespace NBCG::Input::Mouse::Cursor::X
{
    void Update(const SDL_Event& Event)
    {
        Absolute = Event.motion.x;
        Relative = Event.motion.xrel;
        Changed = Relative;
    }
}