#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <source_location>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <memory>
#include <optional>
#include <array>

#pragma warning(push)
#pragma warning(disable : 26819 26451)
#include "..\\glew\\glew.h"
#include "..\\sdl\\sdl_opengl.h"
#include "..\\sdl\\sdl_image.h"
#include "..\\glm\\glm.hpp"
#include "..\\glm\\gtc\\matrix_transform.hpp"
#include "..\\glm\\gtc\\type_ptr.hpp"
#pragma warning(pop)

#include <gl\\glu.h>

namespace NBCG
{
    inline class CEngine
    {
        private:
            friend signed int ::main(signed int , char**);
        private:
            void PInitialize();
            void PInitiate();
        public:
            CEngine();
            ~CEngine();
    }
    GEngine;
}