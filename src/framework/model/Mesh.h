#pragma once

#include "Geometry.h"
#include "Material.h"

// TODO remove additional dependencies
#include "../opengl/shader/ShaderProgram.h"
//#include "../opengl/Texture0/Texture0.h"

class Mesh {
public:
    Geometry geometry;
    Material material;

public:
    Mesh(Geometry geometry, Material material);
    void draw(ShaderProgram* shaderProgram);
};

