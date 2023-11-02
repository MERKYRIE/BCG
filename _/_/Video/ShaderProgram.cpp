#include "ShaderProgram.hpp"

#include "Debug.hpp"

namespace NBCG::NVideo
{
    void CShaderProgram::PInitialize()
    {
        FIdentifier = glCreateProgram();
        for(const auto& LShader : std::vector<std::tuple<std::string , unsigned int>>{{"Shaders\\Vertex.glsl" , GL_VERTEX_SHADER} , {"Shaders\\Fragment.glsl" , GL_FRAGMENT_SHADER}})
        {
            std::ifstream LShaderFileStream{std::get<0>(LShader)};
            GDebug.PError(!LShaderFileStream);
            std::ostringstream LShaderStringStream;
            LShaderStringStream << LShaderFileStream.rdbuf();
            std::string LShaderString{LShaderStringStream.str()};
            const char* LShaderPointer{LShaderString.c_str()};
            unsigned int LShaderIdentifier{glCreateShader(std::get<1>(LShader))};
            glShaderSource(LShaderIdentifier , 1 , &LShaderPointer , nullptr);
            glCompileShader(LShaderIdentifier);
            glAttachShader(FIdentifier , LShaderIdentifier);
            glDeleteShader(LShaderIdentifier);
        }
        glLinkProgram(FIdentifier);
        glUseProgram(FIdentifier);
        GDebug.POGL();
    }

    CShaderProgram& CShaderProgram::PUniform(const std::string& AVariable , float AX)
    {
        glUniform1f(glGetUniformLocation(FIdentifier , AVariable.c_str()) , AX);
        return *this;
    }

    CShaderProgram& CShaderProgram::PUniform1(const std::string& AVariable , std::vector<float> AArray)
    {
        glUniform1fv(glGetUniformLocation(FIdentifier , AVariable.c_str()) , static_cast<signed int>(AArray.size()) , AArray.data());
        return *this;
    }

    CShaderProgram& CShaderProgram::PUniform(const std::string& AVariable , signed int AX)
    {
        glUniform1i(glGetUniformLocation(FIdentifier , AVariable.c_str()) , AX);
        return *this;
    }

    CShaderProgram& CShaderProgram::PUniform1(const std::string& AVariable , std::vector<signed int> AArray)
    {
        glUniform1iv(glGetUniformLocation(FIdentifier , AVariable.c_str()) , static_cast<signed int>(AArray.size()) , AArray.data());
        return *this;
    }

    CShaderProgram& CShaderProgram::PUniform(const std::string& AVariable , float AX , float AY)
    {
        glUniform2f(glGetUniformLocation(FIdentifier , AVariable.c_str()) , AX , AY);
        return *this;
    }

    CShaderProgram& CShaderProgram::PUniform2(const std::string& AVariable , std::vector<float> AArray)
    {
        glUniform2fv(glGetUniformLocation(FIdentifier , AVariable.c_str()) , static_cast<signed int>(AArray.size()) , AArray.data());
        return *this;
    }

    CShaderProgram& CShaderProgram::PUniform(const std::string& AVariable , signed int AX , signed int AY)
    {
        glUniform2i(glGetUniformLocation(FIdentifier , AVariable.c_str()) , AX , AY);
        return *this;
    }

    CShaderProgram& CShaderProgram::PUniform2(const std::string& AVariable , std::vector<signed int> AArray)
    {
        glUniform2iv(glGetUniformLocation(FIdentifier , AVariable.c_str()) , static_cast<signed int>(AArray.size()) , AArray.data());
        return *this;
    }

    CShaderProgram& CShaderProgram::PUniform(const std::string& AVariable , float AX , float AY , float AZ)
    {
        glUniform3f(glGetUniformLocation(FIdentifier , AVariable.c_str()) , AX , AY , AZ);
        return *this;
    }

    CShaderProgram& CShaderProgram::PUniform3(const std::string& AVariable , std::vector<float> AArray)
    {
        glUniform3fv(glGetUniformLocation(FIdentifier , AVariable.c_str()) , static_cast<signed int>(AArray.size()) , AArray.data());
        return *this;
    }

    CShaderProgram& CShaderProgram::PUniform(const std::string& AVariable , signed int AX , signed int AY , signed int AZ)
    {
        glUniform3i(glGetUniformLocation(FIdentifier , AVariable.c_str()) , AX , AY , AZ);
        return *this;
    }

    CShaderProgram& CShaderProgram::PUniform3(const std::string& AVariable , std::vector<signed int> AArray)
    {
        glUniform3iv(glGetUniformLocation(FIdentifier , AVariable.c_str()) , static_cast<signed int>(AArray.size()) , AArray.data());
        return *this;
    }

    CShaderProgram& CShaderProgram::PUniform(const std::string& AVariable , float AX , float AY , float AZ , float AW)
    {
        glUniform4f(glGetUniformLocation(FIdentifier , AVariable.c_str()) , AX , AY , AZ , AW);
        return *this;
    }

    CShaderProgram& CShaderProgram::PUniform4(const std::string& AVariable , std::vector<float> AArray)
    {
        glUniform4fv(glGetUniformLocation(FIdentifier , AVariable.c_str()) , static_cast<signed int>(AArray.size()) , AArray.data());
        return *this;
    }

    CShaderProgram& CShaderProgram::PUniform(const std::string& AVariable , signed int AX , signed int AY , signed int AZ , signed int AW)
    {
        glUniform4i(glGetUniformLocation(FIdentifier , AVariable.c_str()) , AX , AY , AZ , AW);
        return *this;
    }

    CShaderProgram& CShaderProgram::PUniform4(const std::string& AVariable , std::vector<signed int> AArray)
    {
        glUniform4iv(glGetUniformLocation(FIdentifier , AVariable.c_str()) , static_cast<signed int>(AArray.size()) , AArray.data());
        return *this;
    }
}