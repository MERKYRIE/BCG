#pragma once

#include "Core.hpp"

namespace NBCG
{
    class CFace
    {
        private:
            std::vector<unsigned int> FIndices;
        public:
            CFace(const aiFace& AFace);
            void PRender(const std::vector<aiVector3D>& AVertices , const std::vector<aiVector2D>& ACoordinates) const;
    };
}