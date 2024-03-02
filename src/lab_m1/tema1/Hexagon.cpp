//
// Created by Alexia Stefan on 11.11.2023.
//

#include "Hexagon.h"

using namespace m1;


Hexagon::Hexagon(const string &name, const glm::vec3 &center, float length, const glm::vec3 &color, float z, bool fill)
        : Shape(name, center, length, color, z, fill) {}


Mesh *Hexagon::CreateMyFullHexa(

        const std::string &name,
        glm::vec3 center1,
        glm::vec3 center2,
        float big_length,
        float small_length,
        glm::vec3 big_color,
        glm::vec3 small_color,
        float z,
        bool fill
) {

    std::vector<VertexFormat> vertices = {

            VertexFormat(center1, big_color),
            VertexFormat(center1 + glm::vec3(big_length, 0, z), big_color),  // 1
            VertexFormat(center1 + glm::vec3(0.75f * big_length, big_length, z), big_color), //2
            VertexFormat(center1 + glm::vec3(-0.75f * big_length, big_length, z), big_color),    // 3
            VertexFormat(center1 + glm::vec3(-big_length, 0, z), big_color),     // 4
            VertexFormat(center1 + glm::vec3(-0.75f * big_length, -big_length, z), big_color),
            VertexFormat(center1 + glm::vec3(0.75f * big_length, -big_length, z), big_color)
    };

    std::vector<VertexFormat> inner_vertices = {

            VertexFormat(center2, small_color),
            VertexFormat(center2 + glm::vec3(small_length, 0, z), small_color),  // 1
            VertexFormat(center2 + glm::vec3(0.75f * small_length, small_length, z), small_color), //2
            VertexFormat(center2 + glm::vec3(-0.75f * small_length, small_length, z), small_color),    // 3
            VertexFormat(center2 + glm::vec3(-small_length, 0, z), small_color),     // 4
            VertexFormat(center2 + glm::vec3(-0.75f * small_length, -small_length, z), small_color),
            VertexFormat(center2 + glm::vec3(0.75f * small_length, -small_length, z), small_color)
    };
    vertices.insert(vertices.end(), inner_vertices.begin(), inner_vertices.end());

    Mesh *hexagon = new Mesh(name);
    hexagon->SetDrawMode(GL_TRIANGLES);
    std::vector<unsigned int> indices = {

            // outer:
            0, 1, 2,
            0, 2, 3,
            0, 3, 4,
            5, 0, 4,
            6, 0, 5,
            6, 1, 0,

            //inner:
            7, 8, 9,
            7, 9, 10,
            7, 10, 11,
            12, 7, 11,
            13, 7, 12,
            13, 8, 7
    };


    hexagon->InitFromData(vertices, indices);
    return hexagon;
}

glm::mat3 Hexagon::DrawMovingHexP1(float x, float y, float tr_x, float tr_y) {

    glm::mat3 modelMatrix = glm::mat3(1);
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(x, y);
    modelMatrix *= transform2D::Translate(tr_x, tr_y);

    return modelMatrix;

}






