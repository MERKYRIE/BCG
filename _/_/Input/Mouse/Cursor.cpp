#include "Cursor.hpp"

#include "Cursor\\X.hpp"
#include "Cursor\\Y.hpp"

namespace NBCG::NInput::NMouse
{
    void CCursor::PInitialize()
    {
        SDL_ShowCursor(SDL_DISABLE);
        SDL_WarpMouseInWindow(nullptr , 0 , 0);
    }

    void CCursor::PUpdate(const SDL_Event& AEvent)
    {
        NCursor::GX.PUpdate(AEvent);
        NCursor::GY.PUpdate(AEvent);
    }
}