//
// Created by Alexia Stefan on 11.11.2023.
//

#include "Square.h"

using namespace m1;


Square::Square(const string &name, const glm::vec3 &center, float length, const glm::vec3 &color, float z, bool fill)
        : Shape(name, center, length, color, z, fill) {}

Mesh *Square::createMySquare(
        const std::string &name,
        glm::vec3 leftBottomCorner,
        float length,
        glm::vec3 color,
        float z,
        bool fill) {

    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
            {
                    VertexFormat(corner, color),
                    VertexFormat(corner + glm::vec3(length, 0, z), color),
                    VertexFormat(corner + glm::vec3(length, length, z), color),
                    VertexFormat(corner + glm::vec3(0, length, z), color)
            };

    Mesh *square = new Mesh(name);
    std::vector<unsigned int> indices = {0, 1, 2, 3};

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    } else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}


glm::mat3 Square::DrawRedZone(float x, float y) {

    glm::mat3 modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(x, y);
    //modelMatrix *= transform2D::Scale(1, 8.1f);
    modelMatrix *= transform2D::Scale(1, 8.5f);
    return modelMatrix;
}

glm::mat3 Square::DrawGreenSquare(float x, float y) {

    glm::mat3 modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(x, y);
    return modelMatrix;
}
