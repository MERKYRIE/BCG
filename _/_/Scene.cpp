#include "Core.hpp"

namespace NBCG
{
    CScene::CScene(const aiScene* AScene , const aiNode* ANode)
    {
        PTransformation.Set(ANode->mTransformation.a4 , ANode->mTransformation.b4 , ANode->mTransformation.c4);
        for(unsigned int LMesh{0} ; LMesh < ANode->mNumMeshes ; LMesh++)
        {
            PMeshes.emplace_back(AScene->mMeshes[ANode->mMeshes[LMesh]]);
        }
        for(unsigned int LChild{0} ; LChild < ANode->mNumChildren ; LChild++)
        {
            PChildren.emplace_back(AScene , ANode->mChildren[LChild]);
        }
    }

    void CScene::MRender(const std::vector<CMaterial>& AMaterials) const
    {
        glTranslated(PTransformation.x , PTransformation.y , PTransformation.z);
        for(const CMesh& LMesh : PMeshes)
        {
            LMesh.MRender(AMaterials);
        }
        for(const CScene& LChild : PChildren)
        {
            LChild.MRender(AMaterials);
        }
        glTranslated(-PTransformation.x , -PTransformation.y , -PTransformation.z);
    }
}