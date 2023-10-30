#pragma once

namespace NBCG
{
    class CScene
    {
        private:
            aiVector3D PTransformation;
            std::vector<CMesh> PMeshes;
            std::vector<CScene> PChildren;
        public:
            CScene(const aiScene* AScene , const aiNode* ANode);
            void MRender(const std::vector<CMaterial>& AMaterials) const;
    };
}