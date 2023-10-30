#pragma once

namespace NBCG
{
    class CMesh
    {
        private:
            unsigned int PMaterial;
            std::vector<aiVector3D> PVertices;
            std::vector<aiVector2D> PCoordinates;
            std::vector<CFace> PFaces;
        public:
            CMesh(const aiMesh* AMesh);
            void MRender(const std::vector<CMaterial>& AMaterials) const;
    };
}