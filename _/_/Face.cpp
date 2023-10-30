#include "Core.hpp"

namespace NBCG
{
    CFace::CFace(const aiFace& AFace)
    {
        for(unsigned int LIndex{0} ; LIndex < AFace.mNumIndices ; LIndex++)
        {
            PIndices.push_back(AFace.mIndices[LIndex]);
        }
    }

    void CFace::MRender(const std::vector<aiVector3D>& AVertices , const std::vector<aiVector2D>& ACoordinates) const
    {
        switch(PIndices.size())
        {
            case 1:
                glBegin(GL_POINTS);
            break;
            case 2:
                glBegin(GL_LINES);
            break;
            case 3:
                glBegin(GL_TRIANGLES);
            break;
            case 4:
                glBegin(GL_QUADS);
            break;
            default:
                glBegin(GL_POLYGON);
            break;
        }
        for(unsigned int LIndex : PIndices)
        {
            glTexCoord2d(ACoordinates[LIndex].x , ACoordinates[LIndex].y);
            glVertex3d(AVertices[LIndex].x , AVertices[LIndex].y , AVertices[LIndex].z);
        }
        glEnd();
    }
}