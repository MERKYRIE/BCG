#pragma once

#include "Core.hpp"

namespace NBCG::NVideo
{
    inline class CShaderProgram
    {
        private:
            friend class CVideo;
        private:
            unsigned int FIdentifier;
        private:
            void PInitialize();
        public:
            CShaderProgram& PUniform(const std::string& AVariable , float AX);
            CShaderProgram& PUniform1(const std::string& AVariable , std::vector<float> AArray);
            CShaderProgram& PUniform(const std::string& AVariable , signed int AX);
            CShaderProgram& PUniform1(const std::string& AVariable , std::vector<signed int> AArray);
            CShaderProgram& PUniform(const std::string& AVariable , float AX , float AY);
            CShaderProgram& PUniform2(const std::string& AVariable , std::vector<float> AArray);
            CShaderProgram& PUniform(const std::string& AVariable , signed int AX , signed int AY);
            CShaderProgram& PUniform2(const std::string& AVariable , std::vector<signed int> AArray);
            CShaderProgram& PUniform(const std::string& AVariable , float AX , float AY , float AZ);
            CShaderProgram& PUniform3(const std::string& AVariable , std::vector<float> AArray);
            CShaderProgram& PUniform(const std::string& AVariable , signed int AX , signed int AY , signed int AZ);
            CShaderProgram& PUniform3(const std::string& AVariable , std::vector<signed int> AArray);
            CShaderProgram& PUniform(const std::string& AVariable , float AX , float AY , float AZ , float AW);
            CShaderProgram& PUniform4(const std::string& AVariable , std::vector<float> AArray);
            CShaderProgram& PUniform(const std::string& AVariable , signed int AX , signed int AY , signed int AZ , signed int AW);
            CShaderProgram& PUniform4(const std::string& AVariable , std::vector<signed int> AArray);
    }
    GShaderProgram;
}