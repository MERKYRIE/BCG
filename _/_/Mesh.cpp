#include "Mesh.hpp"

namespace NBCG
{
    CMesh::CMesh(const aiMesh* AMesh)
    {
        FMaterial = AMesh->mMaterialIndex;
        for(unsigned int LVertex{0} ; LVertex < AMesh->mNumVertices ; LVertex++)
        {
            FVertices.emplace_back(AMesh->mVertices[LVertex].x , AMesh->mVertices[LVertex].y , AMesh->mVertices[LVertex].z);
            FCoordinates.emplace_back(AMesh->mTextureCoords[0][LVertex].x , AMesh->mTextureCoords[0][LVertex].y);
        }
        for(unsigned int LFace{0} ; LFace < AMesh->mNumFaces ; LFace++)
        {
            FFaces.emplace_back(AMesh->mFaces[LFace]);
        }
    }

    void CMesh::PRender(const std::vector<CMaterial>& AMaterials) const
    {
        glColor4ub(255 , 255 , 255 , 255);
        AMaterials[FMaterial].PBind();
        for(const CFace& LFace : FFaces)
        {
            LFace.PRender(FVertices , FCoordinates);
        }
    }
}