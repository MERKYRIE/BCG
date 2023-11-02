#include "Model.hpp"

#include "Debug.hpp"

namespace NBCG
{
    CModel::CModel(const std::string& APath)
    {
        const aiScene* LScene;
        GDebug.PAI(LScene = aiImportFile(("Models" + APath).c_str() , 0));
        for(unsigned int LMaterial{0} ; LMaterial < LScene->mNumMaterials ; LMaterial++)
        {
            if(!GDebug.PWarning(aiGetMaterialTextureCount(LScene->mMaterials[LMaterial] , aiTextureType_DIFFUSE) != 1 && aiGetMaterialTextureCount(LScene->mMaterials[LMaterial] , aiTextureType_BASE_COLOR) != 1))
            {
                FMaterials.emplace_back(LScene->mMaterials[LMaterial]);
            }
            else
            {
                FMaterials.emplace_back(LScene->mMaterials[LMaterial]);
            }
        }
        for(unsigned int VMesh{0} ; VMesh < LScene->mNumMeshes ; VMesh++)
        {
            GDebug.PError(LScene->mMeshes[VMesh]->mNumUVComponents[0] != 2);
            GDebug.PError(LScene->mMeshes[VMesh]->mPrimitiveTypes & aiPrimitiveType_NGONEncodingFlag);
            GDebug.PError(LScene->mMeshes[VMesh]->mMaterialIndex >= FMaterials.size());
        }
        FScene = std::make_unique<CScene>(LScene , LScene->mRootNode);
        aiReleaseImport(LScene);
    }

    void CModel::PRender(double AX , double AY , double AZ) const
    {
        /*
        glTranslated(AX , AY , AZ);
        PScene->MRender(PMaterials);
        glTranslated(-AX , -AY , -AZ);
        */
    }
}