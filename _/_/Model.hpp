#pragma once

#include "Core.hpp"

#include "Material.hpp"
#include "Scene.hpp"

namespace NBCG
{
    class CModel
    {
        private:
            std::vector<CMaterial> FMaterials;
            std::optional<CScene> FScene;
            std::vector<aiVector3D> FVertices;
            std::vector<unsigned int> FIndices;
        public:
            CModel(const std::string& APath);
            void PRender(double AX , double AY , double AZ) const;
    };
}