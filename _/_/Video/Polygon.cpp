#include "Polygon.hpp"

#include "ShaderProgram.hpp"
#include "VAO\\VBO.hpp"
#include "VAO\\EBO.hpp"

#include "Debug.hpp"
#include "Video.hpp"

namespace NBCG::NVideo
{
    CPolygon::CPolygon()
    {
        FVertices = {{0.0F , 0.0F} , {0.0F , 0.0F} , {0.0F , 0.0F} , {0.0F , 0.0F}};
        FIndices = {0 , 1 , 2 , 2 , 3 , 0};
        FColor = {0.0F , 0.0F , 0.0F , 0.0F};
    }

    float CPolygon::PX()
    {
        return FX;
    }

    CPolygon& CPolygon::PX(float AX)
    {
        FX = AX;
        return *this;
    }

    float CPolygon::PY()
    {
        return FY;
    }

    CPolygon& CPolygon::PY(float AY)
    {
        FY = AY;
        return *this;
    }

    float CPolygon::PWidth()
    {
        return FWidth;
    }

    CPolygon& CPolygon::PWidth(float AWidth)
    {
        FWidth = AWidth;
        return *this;
    }

    float CPolygon::PHeight()
    {
        return FHeight;
    }

    CPolygon& CPolygon::PHeight(float AHeight)
    {
        FHeight = AHeight;
        return *this;
    }

    std::array<float , 4> CPolygon::PColor()
    {
        return FColor;
    }

    CPolygon& CPolygon::PColor(const std::array<float , 4>& AColor)
    {
        FColor = AColor;
        return *this;
    }

    CPolygon& CPolygon::PCorrectToWidth()
    {
        FY += (FWidth * GVideo.PRatio() - FHeight) / 2.0F;
        FHeight = FWidth * GVideo.PRatio();
        return *this;
    }

    CPolygon& CPolygon::PCorrectToHeight()
    {
        FX += (FWidth - FHeight * GVideo.PInversedRatio()) / 2.0F;
        FWidth = FHeight * GVideo.PInversedRatio();
        return *this;
    }

    CPolygon& CPolygon::PUpdate()
    {
        FVertices = {{FX , FY} , {FX + FWidth , FY} , {FX + FWidth , FY + FHeight} , {FX , FY + FHeight}};
        return *this;
    }

    CPolygon& CPolygon::PRender()
    {
        NVideo::GVBO.PBuffer(FVertices);
        NVideo::GEBO.PBuffer(FIndices);
        GShaderProgram.PColor(FColor);
        glDrawElements(GL_TRIANGLES , static_cast<signed int>(FIndices.size()) , GL_UNSIGNED_INT , nullptr);
        return *this;
    }
}