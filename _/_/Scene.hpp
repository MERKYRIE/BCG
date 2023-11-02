#pragma once

#include "Core.hpp"

#include "Mesh.hpp"

namespace NBCG
{
    class CScene
    {
        private:
            aiVector3D FTransformation;
            std::vector<CMesh> FMeshes;
            std::vector<CScene> FChildren;
        public:
            CScene(const aiScene* AScene , const aiNode* ANode);
            void PRender(const std::vector<CMaterial>& AMaterials) const;
    };
}