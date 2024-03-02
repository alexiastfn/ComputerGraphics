//
// Created by Alexia Stefan on 11.11.2023.
//

#ifndef GFXFRAMEWORK_ROMB_H
#define GFXFRAMEWORK_ROMB_H

#include "Shape.h"
#include "Star.h"

namespace m1 {
    class Romb : public Shape, public Star {
    public:
        float location[1][2];
        float btn_x_update;
        int type;
        vector<Star *> tableStars_romb;
        int NO_STARS;
        int nrRand;
        int nrColoana;
        float collisionHappened = false;
        float disp_sx = 0.5f;
        float disp_sy = 0.5f;
        glm::mat3 modelMatrix;

        Romb(const string &name, const glm::vec3 &center, float length, const glm::vec3 &color, float z, bool fill);

        Mesh *createMyRomb(const std::string &name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, float z,
                           bool fill = false);

        glm::mat3 DrawRomb(float x, float y);


    };
}

#endif //GFXFRAMEWORK_ROMB_H
