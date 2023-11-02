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
            std::unique_ptr<CScene> FScene;
        public:
            CModel(const std::string& APath);
            void PRender(double AX , double AY , double AZ) const;
    };
}