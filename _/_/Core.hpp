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
#include "..\\sdl\\sdl_image.h"
#include "..\\assimp\\scene.h"
#include "..\\assimp\\cimport.h"
#pragma warning(pop)

#include "Texture.hpp"
#include "Material.hpp"
#include "Face.hpp"
#include "Mesh.hpp"
#include "Scene.hpp"
#include "Model.hpp"

#include "Debug.hpp"
#include "Time.hpp"

#include "Video.hpp"
#include "Video\\ShaderProgram.hpp"
#include "Video\\VertexBufferObject.hpp"
#include "Video\\ElementBufferObject.hpp"
#include "Video\\VertexArrayBuffer.hpp"
#include "Input.hpp"