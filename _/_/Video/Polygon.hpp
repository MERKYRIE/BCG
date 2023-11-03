#pragma once

#include "Engine.hpp"

namespace NBCG::NVideo
{
    class CPolygon
    {
        private:
            float FX;
            float FY;
            float FWidth;
            float FHeight;
            std::array<float , 4> FColor;
            std::vector<std::array<float , 2>> FVertices;
            std::vector<unsigned int> FIndices;
        public:
            CPolygon();
            float PX();
            CPolygon& PX(float AX);
            float PY();
            CPolygon& PY(float AY);
            float PWidth();
            CPolygon& PWidth(float AWidth);
            float PHeight();
            CPolygon& PHeight(float AHeight);
            std::array<float , 4> PColor();
            CPolygon& PColor(const std::array<float , 4>& AColor);
            CPolygon& PCorrectToWidth();
            CPolygon& PCorrectToHeight();
            CPolygon& PUpdate();
            CPolygon& PRender();
    };
}