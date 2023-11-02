#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <source_location>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <memory>

#pragma warning(push)
#pragma warning(disable : 26819 26451)
#include "..\\glew\\glew.h"
#include "..\\sdl\\sdl_opengl.h"
#include "..\\sdl\\sdl_image.h"
#include "..\\assimp\\scene.h"
#include "..\\assimp\\cimport.h"
#pragma warning(pop)

#include <gl\\glu.h>

namespace NBCG
{
    inline class CCore
    {
        private:
            friend signed int ::main(signed int , char**);
        private:
            void PUpdate();
        public:
            CCore();
            ~CCore();
    }
    GCore;
}