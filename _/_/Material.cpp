#include "Core.hpp"

namespace NBCG
{
    CMaterial::CMaterial(const aiMaterial* AMaterial)
    {
        if(aiGetMaterialTextureCount(AMaterial , aiTextureType_DIFFUSE))
        {
            aiString LString;
            aiGetMaterialTexture(AMaterial , aiTextureType_DIFFUSE , 0 , &LString);
            PTexture = std::make_unique<CTexture>("\\" + std::string{LString.C_Str()});
        }
        if(aiGetMaterialTextureCount(AMaterial , aiTextureType_BASE_COLOR))
        {
            aiString LString;
            aiGetMaterialTexture(AMaterial , aiTextureType_BASE_COLOR , 0 , &LString);
            PTexture = std::make_unique<CTexture>("\\" + std::string{LString.C_Str()});
        }
    }

    void CMaterial::MBind() const
    {
        PTexture->MBind();
    }
}