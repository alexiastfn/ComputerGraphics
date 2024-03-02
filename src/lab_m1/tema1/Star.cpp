//
// Created by Alexia Stefan on 11.11.2023.
//

#include "Star.h"

using namespace m1;


Star::Star(const string &name, const glm::vec3 &center, float length, const glm::vec3 &color, float z, bool fill)
        : Shape(name, center, length, color, z, fill) {}

Mesh *Star::createMyStar(const std::string &name,
                         glm::vec3 leftBottomCorner,
                         float length,
                         glm::vec3 color,
                         float z,
                         bool fill) {

    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
            {
                    VertexFormat(corner, color),                                                    // 0
                    VertexFormat(corner + glm::vec3(0, length, z), color),                 // 1
                    VertexFormat(corner + glm::vec3(-length, -length, z), color),          // 2
                    VertexFormat(corner + glm::vec3(length, -length, z), color),           // 3
                    VertexFormat(corner + glm::vec3(-1.2f * length, 0.5f * length, z), color),    // 4
                    VertexFormat(corner + glm::vec3(1.2f * length, 0.5f * length, z), color)      // 5

            };

    Mesh *square = new Mesh(name);
    std::vector<unsigned int> indices = {
            0, 1, 2,
            0, 3, 1,
            0, 5, 4
    };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    } else {

        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}

glm::mat3 Star::DrawStar(float x, float y) {

    glm::mat3 modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(x, y);
    return modelMatrix;
}

glm::mat3 Star::DrawMovingStarP1(float x, float y, float tr_x, float tr_y) {

    glm::mat3 modelMatrix = glm::mat3(1);
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(x, y);
    modelMatrix *= transform2D::Translate(tr_x, tr_y);
    return modelMatrix;

}

glm::mat3 Star::DrawMovingStarP2(float angularStep) {

    glm::mat3 modelMatrix = glm::mat3(1);
    float hexa_length = 5;
    modelMatrix *= transform2D::Translate(hexa_length / 2.f, hexa_length / 2.f);
    modelMatrix *= transform2D::Rotate(angularStep);
    return modelMatrix;

}

glm::mat3 Star::StarAnimation(Star *tableStar, float delta) {

    glm::mat3 modelMatrix = glm::mat3(1);
    modelMatrix = tableStar->DrawMovingStarP1(tableStar->location[0][0],
                                              tableStar->location[0][1],
                                              tableStar->translateX_star,
                                              tableStar->translateY_star);
    tableStar->angularStep += 1.5f * delta;
    modelMatrix *= tableStar->DrawMovingStarP2(tableStar->angularStep);
    tableStar->translateX_star += 100 * delta;
    tableStar->location[0][0] += 100 * delta;

    return modelMatrix;

}

