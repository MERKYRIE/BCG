#pragma once

namespace NBCG
{
    class CFace
    {
        private:
            std::vector<unsigned int> PIndices;
        public:
            CFace(const aiFace& AFace);
            void MRender(const std::vector<aiVector3D>& AVertices , const std::vector<aiVector2D>& ACoordinates) const;
    };
}