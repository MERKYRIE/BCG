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
        static glm::mat4 LProjection{glm::ortho(0.0F , 100.0F , 100.0F , 0.0F)};
        static signed int LProjectionLocation{glGetUniformLocation(FIdentifier , "UProjection")};
        glUniformMatrix4fv(LProjectionLocation , 1 , GL_FALSE , &LProjection[0][0]);
        static glm::mat4 LView{1.0F};
        static signed int LViewLocation{glGetUniformLocation(FIdentifier , "UView")};
        glUniformMatrix4fv(LViewLocation , 1 , GL_FALSE , &LView[0][0]);
        static glm::mat4 LModel{1.0F};
        static signed int LModelLocation{glGetUniformLocation(FIdentifier , "UModel")};
        glUniformMatrix4fv(LModelLocation , 1 , GL_FALSE , &LModel[0][0]);
    }

    CShaderProgram& CShaderProgram::PColor(const std::array<float , 4> AColor)
    {
        static signed int LColor{glGetUniformLocation(FIdentifier , "UColor")};
        glUniform4fv(LColor , 1 , AColor.data());
        return *this;
    }
}