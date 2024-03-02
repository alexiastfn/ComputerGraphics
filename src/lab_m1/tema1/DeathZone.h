#pragma once



#include <string>
#include <unordered_map>

#include "lab_m1/tema1/tema1.h"
#include "lab_m1/tema1/transform2D.h"
#include "lab_m1/tema1/object2D.h"

#include "components/simple_scene.h"
#include "core/engine.h"
#include "core/gpu/mesh.h"
#include "core/gpu/shader.h"
#include "utils/glm_utils.h"


class DeathZone
{
public:
    DeathZone();
    ~DeathZone();

    bool playerLifeisOver();    // 0 - mai ai vieti; 1 - ai pierdut (3/3 vieti pierdute)
    void createDeathZone(Mesh *square1, Mesh **meshes, Shader *shader);
    void minusOneLife();


private:
    int red_squareSide;
    int obstacole_counter;
    int obstacole_maximum;
    int start_x;
    int start_y;


};