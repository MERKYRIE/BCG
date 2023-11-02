#include "Model.hpp"

#include "Debug.hpp"
#include "Video\\VertexArrayObject.hpp"

namespace NBCG
{
    CModel::CModel(const std::string& APath)
    {
        const aiScene* LScene;
        GDebug.PAI(LScene = aiImportFile(("Models" + APath).c_str() , 0));
        /*
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
        FScene.emplace(LScene , LScene->mRootNode);
        */
        for(unsigned int LMesh{0} ; LMesh < LScene->mNumMeshes ; LMesh++)
        {
            for(unsigned int LVertex{0} ; LVertex < LScene->mMeshes[LMesh]->mNumVertices ; LVertex++)
            {
                FVertices.emplace_back(LScene->mMeshes[LMesh]->mVertices[LVertex].z , LScene->mMeshes[LMesh]->mVertices[LVertex].x , -LScene->mMeshes[LMesh]->mVertices[LVertex].y);
            }
            for(unsigned int LFace{0} ; LFace < LScene->mMeshes[LMesh]->mNumFaces ; LFace++)
            {
                for(unsigned int LIndex{0} ; LIndex < LScene->mMeshes[LMesh]->mFaces[LFace].mNumIndices ; LIndex++)
                {
                    FIndices.push_back(LScene->mMeshes[LMesh]->mFaces[LFace].mIndices[LIndex]);
                }
            }
        }
        NVideo::GVertexArrayObject.PBuffer(FVertices , FIndices);
        aiReleaseImport(LScene);
    }

    void CModel::PRender(double AX , double AY , double AZ) const
    {
        /*
        glTranslated(AX , AY , AZ);
        PScene->MRender(PMaterials);
        glTranslated(-AX , -AY , -AZ);
        */
        glDrawElements(GL_TRIANGLES , static_cast<signed int>(FIndices.size()) , GL_UNSIGNED_INT , nullptr);
        //glDrawElements(GL_TRIANGLES , 3 , GL_UNSIGNED_INT , nullptr);
    }
}