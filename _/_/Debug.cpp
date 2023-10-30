#include "Core.hpp"

namespace NBCG
{
    void CDebug::MError(bool ACondition , const std::source_location& ALocation)
    {
        if(ACondition)
        {
            if
            (
                SDL_ShowSimpleMessageBox
                (
                    SDL_MESSAGEBOX_ERROR ,
                    "Debug" ,
                    (
                        std::string{} +
                        "File - " + ALocation.file_name() + "\n" +
                        "Function - " + ALocation.function_name() + "\n" +
                        "Line - " + std::to_string(ALocation.line()) + "\n" +
                        "Column - " + std::to_string(ALocation.column())
                    ).data() ,
                    nullptr
                ) < 0
            )
            {
                std::cout << "Debug:" << "\n"
                          << "    File - " << ALocation.file_name() << "\n"
                          << "    Function - " << ALocation.function_name() << "\n"
                          << "    Line - " << ALocation.line() << "\n"
                          << "    Column - " << ALocation.column() << "\n\n";
            }
            std::exit(0);
        }
    }

    bool CDebug::MWarning(bool ACondition , const std::source_location& ALocation)
    {
        if(ACondition)
        {
            if
            (
                SDL_ShowSimpleMessageBox
                (
                    SDL_MESSAGEBOX_WARNING ,
                    "Debug" ,
                    (
                        std::string{} +
                        "File - " + ALocation.file_name() + "\n" +
                        "Function - " + ALocation.function_name() + "\n" +
                        "Line - " + std::to_string(ALocation.line()) + "\n" +
                        "Column - " + std::to_string(ALocation.column())
                    ).data() ,
                    nullptr
                ) < 0
            )
            {
                std::cout << "Debug:" << "\n"
                          << "    File - " << ALocation.file_name() << "\n"
                          << "    Function - " << ALocation.function_name() << "\n"
                          << "    Line - " << ALocation.line() << "\n"
                          << "    Column - " << ALocation.column() << "\n\n";
            }
        }
        return ACondition;
    }
    
    void CDebug::MCode(signed int AValue , const std::source_location& ALocation)
    {
        if(AValue < 0)
        {
            if
            (
                SDL_ShowSimpleMessageBox
                (
                    SDL_MESSAGEBOX_ERROR ,
                    "Debug" ,
                    (
                        std::string{} +
                        "File - " + ALocation.file_name() + "\n" +
                        "Function - " + ALocation.function_name() + "\n" +
                        "Line - " + std::to_string(ALocation.line()) + "\n" +
                        "Column - " + std::to_string(ALocation.column()) + "\n" +
                        "SDL - " + SDL_GetError()
                    ).data() ,
                    nullptr
                ) < 0
            )
            {
                std::cout << "Debug:" << "\n"
                          << "    File - " << ALocation.file_name() << "\n"
                          << "    Function - " << ALocation.function_name() << "\n"
                          << "    Line - " << ALocation.line() << "\n"
                          << "    Column - " << ALocation.column() << "\n"
                          << "    SDL - " << SDL_GetError() << "\n\n";
            }
            std::exit(0);
        }
    }
    
    void CDebug::MHandle(const void* APointer , const std::source_location& ALocation)
    {
        if(!APointer)
        {
            if
            (
                SDL_ShowSimpleMessageBox
                (
                    SDL_MESSAGEBOX_ERROR ,
                    "Debug" ,
                    (
                        std::string{} +
                        "File - " + ALocation.file_name() + "\n" +
                        "Function - " + ALocation.function_name() + "\n" +
                        "Line - " + std::to_string(ALocation.line()) + "\n" +
                        "Column - " + std::to_string(ALocation.column()) + "\n" +
                        "SDL - " + SDL_GetError()
                    ).data() ,
                    nullptr
                ) < 0
            )
            {
                std::cout << "Debug:" << "\n"
                          << "    File - " << ALocation.file_name() << "\n"
                          << "    Function - " << ALocation.function_name() << "\n"
                          << "    Line - " << ALocation.line() << "\n"
                          << "    Column - " << ALocation.column() << "\n"
                          << "    SDL - " << SDL_GetError() << "\n\n";
            }
            std::exit(0);
        }
    }

    void CDebug::MFlags(signed int AValue , const std::source_location& ALocation)
    {
        if(!AValue)
        {
            if
            (
                SDL_ShowSimpleMessageBox
                (
                    SDL_MESSAGEBOX_ERROR ,
                    "Debug" ,
                    (
                        std::string{} +
                        "File - " + ALocation.file_name() + "\n" +
                        "Function - " + ALocation.function_name() + "\n" +
                        "Line - " + std::to_string(ALocation.line()) + "\n" +
                        "Column - " + std::to_string(ALocation.column()) + "\n" +
                        "SDL - " + SDL_GetError()
                    ).data() ,
                    nullptr
                ) < 0
            )
            {
                std::cout << "Debug:" << "\n"
                          << "    File - " << ALocation.file_name() << "\n"
                          << "    Function - " << ALocation.function_name() << "\n"
                          << "    Line - " << ALocation.line() << "\n"
                          << "    Column - " << ALocation.column() << "\n"
                          << "    SDL - " << SDL_GetError() << "\n\n";
            }
            std::exit(0);
        }
    }

    void CDebug::MOGL(const std::source_location& ALocation)
    {
        GLenum LCode{glGetError()};
        if(LCode != GL_NO_ERROR)
        {
            if
            (
                SDL_ShowSimpleMessageBox
                (
                    SDL_MESSAGEBOX_ERROR ,
                    "Debug" ,
                    (
                        std::string{} +
                        "File - " + ALocation.file_name() + "\n" +
                        "Function - " + ALocation.function_name() + "\n" +
                        "Line - " + std::to_string(ALocation.line()) + "\n" +
                        "Column - " + std::to_string(ALocation.column()) + "\n" +
                        "OGL - " + reinterpret_cast<const char*>(gluErrorString(LCode))
                    ).data() ,
                    nullptr
                ) < 0
            )
            {
                std::cout << "Debug:" << "\n"
                          << "    File - " << ALocation.file_name() << "\n"
                          << "    Function - " << ALocation.function_name() << "\n"
                          << "    Line - " << ALocation.line() << "\n"
                          << "    Column - " << ALocation.column() << "\n"
                          << "    OGL - " << reinterpret_cast<const char*>(gluErrorString(LCode)) << "\n\n";
            }
            std::exit(0);
        }
    }

    void CDebug::MAI(const void* AHandle , const std::source_location& ALocation)
    {
        if(!AHandle)
        {
            if
            (
                SDL_ShowSimpleMessageBox
                (
                    SDL_MESSAGEBOX_ERROR ,
                    "Debug" ,
                    (
                        std::string{} +
                        "File - " + ALocation.file_name() + "\n" +
                        "Function - " + ALocation.function_name() + "\n" +
                        "Line - " + std::to_string(ALocation.line()) + "\n" +
                        "Column - " + std::to_string(ALocation.column()) + "\n" +
                        "AI - " + aiGetErrorString()
                    ).data() ,
                    nullptr
                ) < 0
            )
            {
                std::cout << "Debug:" << "\n"
                          << "    File - " << ALocation.file_name() << "\n"
                          << "    Function - " << ALocation.function_name() << "\n"
                          << "    Line - " << ALocation.line() << "\n"
                          << "    Column - " << ALocation.column() << "\n"
                          << "    AI - " << aiGetErrorString() << "\n\n";
            }
            std::exit(0);
        }
    }
}