#include "Core.hpp"

namespace NBCG
{
    CShaderProgram::CShaderProgram()
    {
        PIdentifier = glCreateProgram();
        for(const auto& LShader : std::vector<std::tuple<std::string , unsigned int>>{{"Shaders\\Vertex.glsl" , GL_VERTEX_SHADER} , {"Shaders\\Fragment.glsl" , GL_FRAGMENT_SHADER}})
        {
            std::ifstream LShaderFileStream{std::get<0>(LShader)};
            GDebug.MError(!LShaderFileStream);
            std::ostringstream LShaderStringStream;
            LShaderStringStream << LShaderFileStream.rdbuf();
            std::string LShaderString{LShaderStringStream.str()};
            const char* LShaderPointer{LShaderString.c_str()};
            unsigned int LShaderIdentifier{glCreateShader(std::get<1>(LShader))};
            glShaderSource(LShaderIdentifier , 1 , &LShaderPointer , nullptr);
            glCompileShader(LShaderIdentifier);
            glAttachShader(PIdentifier , LShaderIdentifier);
            glDeleteShader(LShaderIdentifier);
        }
        glLinkProgram(PIdentifier);
        glUseProgram(PIdentifier);
        GDebug.MOGL();
    }

    CShaderProgram& CShaderProgram::MUniform(const std::string& AVariable , float AX)
    {
        glUniform1f(glGetUniformLocation(PIdentifier , AVariable.c_str()) , AX);
        return *this;
    }

    CShaderProgram& CShaderProgram::MUniform1(const std::string& AVariable , std::vector<float> AArray)
    {
        glUniform1fv(glGetUniformLocation(PIdentifier , AVariable.c_str()) , AArray.size() , AArray.data());
        return *this;
    }

    CShaderProgram& CShaderProgram::MUniform(const std::string& AVariable , signed int AX)
    {
        glUniform1i(glGetUniformLocation(PIdentifier , AVariable.c_str()) , AX);
        return *this;
    }

    CShaderProgram& CShaderProgram::MUniform1(const std::string& AVariable , std::vector<signed int> AArray)
    {
        glUniform1iv(glGetUniformLocation(PIdentifier , AVariable.c_str()) , AArray.size() , AArray.data());
        return *this;
    }

    CShaderProgram& CShaderProgram::MUniform(const std::string& AVariable , float AX , float AY)
    {
        glUniform2f(glGetUniformLocation(PIdentifier , AVariable.c_str()) , AX , AY);
        return *this;
    }

    CShaderProgram& CShaderProgram::MUniform2(const std::string& AVariable , std::vector<float> AArray)
    {
        glUniform2fv(glGetUniformLocation(PIdentifier , AVariable.c_str()) , AArray.size() , AArray.data());
        return *this;
    }

    CShaderProgram& CShaderProgram::MUniform(const std::string& AVariable , signed int AX , signed int AY)
    {
        glUniform2i(glGetUniformLocation(PIdentifier , AVariable.c_str()) , AX , AY);
        return *this;
    }

    CShaderProgram& CShaderProgram::MUniform2(const std::string& AVariable , std::vector<signed int> AArray)
    {
        glUniform2iv(glGetUniformLocation(PIdentifier , AVariable.c_str()) , AArray.size() , AArray.data());
        return *this;
    }

    CShaderProgram& CShaderProgram::MUniform(const std::string& AVariable , float AX , float AY , float AZ)
    {
        glUniform3f(glGetUniformLocation(PIdentifier , AVariable.c_str()) , AX , AY , AZ);
        return *this;
    }

    CShaderProgram& CShaderProgram::MUniform3(const std::string& AVariable , std::vector<float> AArray)
    {
        glUniform3fv(glGetUniformLocation(PIdentifier , AVariable.c_str()) , AArray.size() , AArray.data());
        return *this;
    }

    CShaderProgram& CShaderProgram::MUniform(const std::string& AVariable , signed int AX , signed int AY , signed int AZ)
    {
        glUniform3i(glGetUniformLocation(PIdentifier , AVariable.c_str()) , AX , AY , AZ);
        return *this;
    }

    CShaderProgram& CShaderProgram::MUniform(const std::string& AVariable , float AX , float AY , float AZ , float AW)
    {
        glUniform4f(glGetUniformLocation(PIdentifier , AVariable.c_str()) , AX , AY , AZ , AW);
        return *this;
    }
}