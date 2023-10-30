#include "Y.hpp"

namespace NBCG::Input::Mouse::Cursor::Y
{
    void Update(const SDL_Event& Event)
    {
        Absolute = Event.motion.y;
        Relative = Event.motion.yrel;
        Changed = Relative;
    }
}