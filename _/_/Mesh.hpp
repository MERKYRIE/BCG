#pragma once

#include "Core.hpp"

#include "Face.hpp"
#include "Material.hpp"

namespace NBCG
{
    class CMesh
    {
        private:
            unsigned int FMaterial;
            std::vector<aiVector3D> FVertices;
            std::vector<aiVector2D> FCoordinates;
            std::vector<CFace> FFaces;
        public:
            CMesh(const aiMesh* AMesh);
            void PRender(const std::vector<CMaterial>& AMaterials) const;
    };
}