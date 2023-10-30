#include "Core.hpp"

namespace NBCG
{
    CMesh::CMesh(const aiMesh* AMesh)
    {
        PMaterial = AMesh->mMaterialIndex;
        for(unsigned int LVertex{0} ; LVertex < AMesh->mNumVertices ; LVertex++)
        {
            PVertices.emplace_back(AMesh->mVertices[LVertex].x , AMesh->mVertices[LVertex].y , AMesh->mVertices[LVertex].z);
            PCoordinates.emplace_back(AMesh->mTextureCoords[0][LVertex].x , AMesh->mTextureCoords[0][LVertex].y);
        }
        for(unsigned int LFace{0} ; LFace < AMesh->mNumFaces ; LFace++)
        {
            PFaces.emplace_back(AMesh->mFaces[LFace]);
        }
    }

    void CMesh::MRender(const std::vector<CMaterial>& AMaterials) const
    {
        glColor4ub(255 , 255 , 255 , 255);
        AMaterials[PMaterial].MBind();
        for(const CFace& LFace : PFaces)
        {
            LFace.MRender(PVertices , PCoordinates);
        }
    }
}