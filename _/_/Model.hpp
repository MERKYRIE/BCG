#pragma once

namespace NBCG
{
    class CModel
    {
        private:
            std::vector<CMaterial> PMaterials;
            std::unique_ptr<CScene> PScene;
        public:
            CModel(const std::string& APath);
            void MRender(double AX , double AY , double AZ) const;
    };
}