#include "Scene.hpp"

namespace NBCG
{
    CScene::CScene(const aiScene* AScene , const aiNode* ANode)
    {
        FTransformation.Set(ANode->mTransformation.a4 , ANode->mTransformation.b4 , ANode->mTransformation.c4);
        for(unsigned int LMesh{0} ; LMesh < ANode->mNumMeshes ; LMesh++)
        {
            FMeshes.emplace_back(AScene->mMeshes[ANode->mMeshes[LMesh]]);
        }
        for(unsigned int LChild{0} ; LChild < ANode->mNumChildren ; LChild++)
        {
            FChildren.emplace_back(AScene , ANode->mChildren[LChild]);
        }
    }

    void CScene::PRender(const std::vector<CMaterial>& AMaterials) const
    {
        glTranslated(FTransformation.x , FTransformation.y , FTransformation.z);
        for(const CMesh& LMesh : FMeshes)
        {
            LMesh.PRender(AMaterials);
        }
        for(const CScene& LChild : FChildren)
        {
            LChild.PRender(AMaterials);
        }
        glTranslated(-FTransformation.x , -FTransformation.y , -FTransformation.z);
    }
}