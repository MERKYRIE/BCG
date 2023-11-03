#pragma once

#include "Engine.hpp"

#include "Video\\Polygon.hpp"

namespace NBCG
{
    inline class CGame
    {    
        private:
            friend class CEngine;
        private:
            NVideo::CPolygon FUpper;
            NVideo::CPolygon FLower;
            std::array<NVideo::CPolygon , 14> FSeparators;
            std::array<NVideo::CPolygon , 2> FPlayers;
            NVideo::CPolygon FBall;
            glm::vec2 FDirection;
        private:
            void PInitialize();
            void PUpdate();
    }
    GGame;
}