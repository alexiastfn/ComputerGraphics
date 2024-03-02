//
// Created by Alexia Stefan on 11.11.2023.
//

#ifndef GFXFRAMEWORK_STAR_H
#define GFXFRAMEWORK_STAR_H

#include "Shape.h"

namespace m1 {
    class Star : public Shape {
    public:
        int type;
        int nrRand;
        float btn_x_update;
        float location[1][2];
        float angularStep;
        float translateX_star;
        float translateY_star;
        //bool collisionHappened = false;
        float disp_sx = 0.5f;
        float disp_sy = 0.5f;
        glm::mat3 movingStarAnimation;

        Star(const string &name, const glm::vec3 &center, float length, const glm::vec3 &color, float z, bool fill);

        Mesh *createMyStar(const std::string &name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, float z,
                           bool fill = true);

        glm::mat3 DrawMovingStarP1(float x, float y, float tr_x, float tr_y);

        glm::mat3 DrawMovingStarP2(float angularStep);

        glm::mat3 DrawStar(float x, float y);

        glm::mat3 StarAnimation(Star *star, float delta);

    };
}

#endif //GFXFRAMEWORK_STAR_H
