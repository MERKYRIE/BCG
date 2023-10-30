#include "Core.hpp"

namespace NBCG
{
    CTexture::CTexture(const std::string& APath)
    {
        SDL_Surface* LSurface{IMG_Load(("Textures" + APath).c_str())};
        GDebug.MError(!LSurface);
        glGenTextures(1 , &PIdentifier);
        glBindTexture(GL_TEXTURE_2D , PIdentifier);
        switch(LSurface->format->format)
        {
            case SDL_PIXELFORMAT_RGBA32:
                glTexImage2D(GL_TEXTURE_2D , 0 , GL_RGBA , LSurface->w , LSurface->h , 0 , GL_RGBA , GL_UNSIGNED_BYTE , LSurface->pixels);
            break;
            case SDL_PIXELFORMAT_RGB24:
                glTexImage2D(GL_TEXTURE_2D , 0 , GL_RGB , LSurface->w , LSurface->h , 0 , GL_RGB , GL_UNSIGNED_BYTE , LSurface->pixels);
            break;
            case SDL_PIXELFORMAT_INDEX8:
                glTexImage2D(GL_TEXTURE_2D , 0 , GL_RGB8 , LSurface->w , LSurface->h , 0 , GL_COLOR_INDEX , GL_UNSIGNED_BYTE , LSurface->pixels);
            break;
            default:
                GDebug.MError();
            break;
        }
        glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MIN_FILTER , GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MAG_FILTER , GL_NEAREST);
        glBindTexture(GL_TEXTURE_2D , 0);
        GDebug.MOGL();
        SDL_FreeSurface(LSurface);
    }

    void CTexture::MBind() const
    {
        glBindTexture(GL_TEXTURE_2D , PIdentifier);
    }
}