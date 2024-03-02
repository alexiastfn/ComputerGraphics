#pragma once

#include <string>

#include "core/gpu/mesh.h"

#include "utils/glm_utils.h"


namespace object2D {

    // Create square with given bottom left corner, length and color
    Mesh *CreateMySquare(const std::string &name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, float z,
                         bool fill = false);

    Mesh *CreateMyHexa(const std::string &name, glm::vec3 center, float length, glm::vec3 color, float z, bool fill);

    Mesh *CreateHexaWithInnerHexa(const std::string &name, glm::vec3 center, float length, glm::vec3 color, float z,
                                  bool fill);

    Mesh *createAStar(const std::string &name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, float z,
                      bool fill = true);

    Mesh *createARomb(const std::string &name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, float z,
                      bool fill = false);

    Mesh *CreateALightning(const std::string &name, glm::vec3 leftBottomCorner, float length, glm::vec3 color,
                           bool fill = false);
}
