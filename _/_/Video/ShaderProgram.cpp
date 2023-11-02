#include "ShaderProgram.hpp"

#include "Debug.hpp"
#include "Time.hpp"

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

    void CShaderProgram::PUpdate()
    {
        static float LX{0.0F};
        static float LY{0.0F};
        static signed int LLocationX{glGetUniformLocation(FIdentifier , "UX")};
        static signed int LLocationY{glGetUniformLocation(FIdentifier , "UY")};
        if(LX <= 1.5F)
        {
            LX += GTime.PRelative() / 3000.0F;
        }
        else
        {
            LX = -1.5F;
        }
        LY = std::sin(GTime.PAbsolute() / 1000.0F);
        glUniform1f(LLocationX , LX);
        glUniform1f(LLocationY , LY);
    }
}