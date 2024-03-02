#include "DeathZone.h"

/*
DeathZone::DeathZone() {

    red_squareSide = 100;
    obstacole_counter = 0;
    obstacole_maximum = 3;
    start_x = 20;
    start_y = 50;

}

DeathZone::~DeathZone()
{
}

void DeathZone::createDeathZone(Mesh *square1, Mesh **meshes, Shader *shader) {
    glm::vec3 corner = glm::vec3(0, 0, 0);
    square1 = object2D::CreateSquare("square1", corner, red_squareSide, glm::vec3(0.8f, 0, 0), true);
    AddMeshToList(square1);

    glm::mat3 modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(20, 50);
    modelMatrix *= transform2D::Scale(1, 8.1f);
    //RenderMesh2D(square1, shader, modelMatrix);
    RenderMesh2D(square1, shader, modelMatrix);
}
 */