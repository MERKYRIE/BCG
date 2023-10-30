#pragma once

namespace NBCG
{
    inline class CShaderProgram
    {
        private:
            unsigned int PIdentifier;
        public:
            CShaderProgram();
            CShaderProgram& MUniform(const std::string& AVariable , float AX);
            CShaderProgram& MUniform1(const std::string& AVariable , std::vector<float> AArray);
            CShaderProgram& MUniform(const std::string& AVariable , signed int AX);
            CShaderProgram& MUniform1(const std::string& AVariable , std::vector<signed int> AArray);
            CShaderProgram& MUniform(const std::string& AVariable , float AX , float AY);
            CShaderProgram& MUniform2(const std::string& AVariable , std::vector<float> AArray);
            CShaderProgram& MUniform(const std::string& AVariable , signed int AX , signed int AY);
            CShaderProgram& MUniform2(const std::string& AVariable , std::vector<signed int> AArray);
            CShaderProgram& MUniform(const std::string& AVariable , float AX , float AY , float AZ);
            CShaderProgram& MUniform3(const std::string& AVariable , std::vector<float> AArray);
            CShaderProgram& MUniform(const std::string& AVariable , signed int AX , signed int AY , signed int AZ);
            CShaderProgram& MUniform(const std::string& AVariable , float AX , float AY , float AZ , float AW);
    }
    GShaderProgram;
}