//
// Created by Alexia Stefan on 11.11.2023.
//

#ifndef GFXFRAMEWORK_SQUARE_H
#define GFXFRAMEWORK_SQUARE_H

#include "Shape.h"
#include "components/simple_scene.h"
#include "transform2D.h"


namespace m1 {
    class Square : public Shape {
    public:
        float location[1][2];

        Square(const string &name, const glm::vec3 &center, float length, const glm::vec3 &color, float z, bool fill);

        Mesh *
        createMySquare(const std::string &name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, float z,
                       bool fill = false);

        glm::mat3 DrawRedZone(float x, float y);

        glm::mat3 DrawGreenSquare(float x, float y);

    };
}


#endif //GFXFRAMEWORK_SQUARE_H
