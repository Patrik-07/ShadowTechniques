#pragma once

#include "glm/ext/matrix_float4x4.hpp"

struct VertexBoneData {
    int id; // in poses
    glm::mat4 offsetMatrix; // model to bone space

};