#include "Core.hpp"

namespace NBCG
{
    CModel::CModel(const std::string& APath)
    {
        const aiScene* LScene;
        GDebug.MAI(LScene = aiImportFile(("Models" + APath).c_str() , 0));
        for(unsigned int LMaterial{0} ; LMaterial < LScene->mNumMaterials ; LMaterial++)
        {
            if(!GDebug.MWarning(aiGetMaterialTextureCount(LScene->mMaterials[LMaterial] , aiTextureType_DIFFUSE) != 1 && aiGetMaterialTextureCount(LScene->mMaterials[LMaterial] , aiTextureType_BASE_COLOR) != 1))
            {
                PMaterials.emplace_back(LScene->mMaterials[LMaterial]);
            }
            else
            {
                PMaterials.emplace_back(LScene->mMaterials[LMaterial]);
            }
        }
        for(unsigned int VMesh{0} ; VMesh < LScene->mNumMeshes ; VMesh++)
        {
            GDebug.MError(LScene->mMeshes[VMesh]->mNumUVComponents[0] != 2);
            GDebug.MError(LScene->mMeshes[VMesh]->mPrimitiveTypes & aiPrimitiveType_NGONEncodingFlag);
            GDebug.MError(LScene->mMeshes[VMesh]->mMaterialIndex >= PMaterials.size());
        }
        PScene = std::make_unique<CScene>(LScene , LScene->mRootNode);
        aiReleaseImport(LScene);
    }

    void CModel::MRender(double AX , double AY , double AZ) const
    {
        /*
        glTranslated(AX , AY , AZ);
        PScene->MRender(PMaterials);
        glTranslated(-AX , -AY , -AZ);
        */
    }
}