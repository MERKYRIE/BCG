#include "Cursor.hpp"

#include "Cursor\\X.hpp"
#include "Cursor\\Y.hpp"

namespace NBCG::Input::Mouse::Cursor
{
    void Initialize()
    {
        SDL_ShowCursor(SDL_DISABLE);
        SDL_WarpMouseInWindow(nullptr , 0 , 0);
    }

    void Update(const SDL_Event& Event)
    {
        X::Update(Event);
        Y::Update(Event);
    }
}