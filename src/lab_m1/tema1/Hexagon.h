//
// Created by Alexia Stefan on 11.11.2023.
//

#ifndef GFXFRAMEWORK_HEXAGON_H
#define GFXFRAMEWORK_HEXAGON_H

#include "Shape.h"

namespace m1 {
    class Hexagon : public Shape {
    public:
        int type;
        int nrRand;
        float translateX_hex;
        float translateY_hex;
        float deltaTimeSeconds;
        float location[1][2];
        glm::mat3 modelMatrix;
        float disp_sx = 0.5f;
        float disp_sy = 0.5f;
        bool aTrecutDeREDZONE = false;
        bool collisionHappened = false;

        Hexagon(const string &name, const glm::vec3 &center, float length, const glm::vec3 &color, float z, bool fill);

        Mesh *CreateMyFullHexa(const std::string &name, glm::vec3 center1, glm::vec3 center2, float big_length,
                               float small_length, glm::vec3 big_color, glm::vec3 small_color, float z, bool fill);

        glm::mat3 DrawMovingHexP1(float x, float y, float tr_x, float tr_y);

    };
}

#endif //GFXFRAMEWORK_HEXAGON_H
