//
// Created by Alexia Stefan on 01.11.2023.
//
#include "object2D.h"

#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"


Mesh *object2D::CreateMySquare(
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

Mesh *object2D::CreateMyHexa(

        const std::string &name,
        glm::vec3 center,
        float length,
        glm::vec3 color,
        float z,
        bool fill
) {


    std::vector<VertexFormat> vertices = {

            VertexFormat(center, color),
            VertexFormat(center + glm::vec3(length, 0, z), color),  // 1
            VertexFormat(center + glm::vec3(0.75f * length, length, z), color), //2
            VertexFormat(center + glm::vec3(-0.75f * length, length, z), color),    // 3
            VertexFormat(center + glm::vec3(-length, 0, z), color),     // 4
            VertexFormat(center + glm::vec3(-0.75f * length, -length, z), color),
            VertexFormat(center + glm::vec3(0.75f * length, -length, z), color)

    };

    Mesh *hexagon = new Mesh(name);
    std::vector<unsigned int> indices = {
            0, 1, 2,
            0, 2, 3,
            0, 3, 4,
            5, 0, 4,
            6, 0, 5,
            6, 1, 0

    };

    hexagon->SetDrawMode(GL_TRIANGLE_FAN);
    hexagon->InitFromData(vertices, indices);

    return hexagon;
}


Mesh *object2D::createAStar(const std::string &name,
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


Mesh *object2D::createARomb(const std::string &name,
                            glm::vec3 center,
                            float length,
                            glm::vec3 color,
                            float z,
                            bool fill) {


    std::vector<VertexFormat> vertices = {

            VertexFormat(center, color),
            VertexFormat(center + glm::vec3(-length, -length, z), color),  // 1
            VertexFormat(center + glm::vec3(length, -length, z), color), //2
            VertexFormat(center + glm::vec3(0, -2.f * length, z), color), //3
            VertexFormat(center + glm::vec3(0, -0.8f * length, z), color), //4
            VertexFormat(center + glm::vec3(1.5f * length, -0.8f * length, z), color), //5
            VertexFormat(center + glm::vec3(1.5f * length, -1.2f * length, z), color), //6
            VertexFormat(center + glm::vec3(0, -1.2f * length, z), color), //7


    };

    Mesh *hexagon = new Mesh(name);
    std::vector<unsigned int> indices = {
            /*
            0, 1,
            0, 2,
            1, 3,
            2, 3,
            4, 5,
            5, 6,
            6, 7
             */
            2, 0, 1,
            2, 3, 1,
            6, 5, 4,
            6, 7, 4

    };
    /*
    if (!fill) {

    } else {

        indices.push_back(0);
        indices.push_back(2);
    }
     */

    hexagon->SetDrawMode(GL_TRIANGLES);
    hexagon->InitFromData(vertices, indices);

    return hexagon;

}


Mesh *object2D::CreateALightning(const std::string &name,
                                 glm::vec3 center,
                                 float length,
                                 glm::vec3 color,
                                 bool fill) {


    std::vector<VertexFormat> vertices = {

            VertexFormat(center, color),
            VertexFormat(center + glm::vec3(25, length, 0), color),  // 1
            VertexFormat(center + glm::vec3(-80, -30, 0), color),  // 2
            VertexFormat(center + glm::vec3(-65, -30, 0), color),  // 3
            VertexFormat(center + glm::vec3(-40, -length, 0), color),  // 4
            VertexFormat(center + glm::vec3(40, 0, 0), color),  // 5


    };

    Mesh *hexagon = new Mesh(name);
    std::vector<unsigned int> indices = {
            0, 1, 2,
            // 0, 2, 3,
            0, 5, 4

    };
    /*
    if (!fill) {

    } else {

        indices.push_back(0);
        indices.push_back(2);
    }
     */

    hexagon->SetDrawMode(GL_TRIANGLES);
    hexagon->InitFromData(vertices, indices);

    return hexagon;

}