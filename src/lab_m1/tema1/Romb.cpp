//
// Created by Alexia Stefan on 11.11.2023.
//

#include "Romb.h"

using namespace m1;


Romb::Romb(const string &name, const glm::vec3 &center, float length, const glm::vec3 &color, float z, bool fill)
        : Shape(name, center, length, color, z, fill), Star(name, center, length, color, z, fill) {}


Mesh *Romb::createMyRomb(const std::string &name,
                         glm::vec3 center,
                         float length,
                         glm::vec3 color,
                         float z,
                         bool fill) {


    std::vector<VertexFormat> vertices = {

            VertexFormat(center, color),
            VertexFormat(center + glm::vec3(0, 1.25f * length, z), color), // 1
            VertexFormat(center + glm::vec3(-1.25f * length, 0, z), color), // 2
            VertexFormat(center + glm::vec3(0, -1.25f * length, z), color), // 3
            VertexFormat(center + glm::vec3(1.25f * length, 0, z), color), // 4
            VertexFormat(center + glm::vec3(0, 0.5f * length, z), color), // 5
            VertexFormat(center + glm::vec3(1.25f * length, 0.5f * length, z), color), // 6
            VertexFormat(center + glm::vec3(1.25f * length, -0.5f * length, z), color), // 7
            VertexFormat(center + glm::vec3(0, -0.5f * length, z), color) // 8
    };
    Mesh *romb = new Mesh(name);
    std::vector<unsigned int> indices = {
            4, 1, 2,
            4, 3, 2,
            7, 6, 5,
            8, 5, 7

    };

    romb->SetDrawMode(GL_TRIANGLES);
    romb->InitFromData(vertices, indices);

    return romb;

}


glm::mat3 Romb::DrawRomb(float x, float y) {

    glm::mat3 modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(x, y);
    return modelMatrix;
}




