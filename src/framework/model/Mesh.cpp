#include "Mesh.h"

#include <utility>

Mesh::Mesh(Geometry geometry, Material material) :
    geometry(std::move(geometry)), material(std::move(material)) {}

void Mesh::draw(ShaderProgram* shaderProgram) {
    material.update(shaderProgram);
    geometry.draw();
}