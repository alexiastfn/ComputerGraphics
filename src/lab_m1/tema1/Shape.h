//
// Created by Alexia Stefan on 11.11.2023.
//

#ifndef GFXFRAMEWORK_SHAPE_H
#define GFXFRAMEWORK_SHAPE_H

#include "core/gpu/mesh.h"
#include "utils/glm_utils.h"
#include "lab_m1/tema1/transform2D.h"
#include "lab_m1/tema1/object2D.h"
#include "components/simple_scene.h"
#include <stdlib.h>
#include <string>

using namespace std;
namespace m1 {
    class Shape : public gfxc::SimpleScene {
    private:
        string name;
        glm::vec3 center;
        float length;
        glm::vec3 color;
        float z;
        bool fill;

    protected:
        float location[1][1];
    public:
        Shape(const string &name, const glm::vec3 &center, float length, const glm::vec3 &color, float z, bool fill);

        const string &getName() const;

        void setName(const string &name);

        const glm::vec3 &getCenter() const;

        void setCenter(const glm::vec3 &center);

        float getLength() const;

        void setLength(float length);

        const glm::vec3 &getColor() const;

        void setColor(const glm::vec3 &color);

        float getZ() const;

        void setZ(float z);

        bool isFill() const;

        void setFill(bool fill);


    };
}


#endif //GFXFRAMEWORK_SHAPE_H
