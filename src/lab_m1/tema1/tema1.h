#pragma once

#include "components/simple_scene.h"
#include "core/gpu/mesh.h"
#include "lab_m1/tema1/object2D.h"
#include "lab_m1/tema1/transform2D.h"
#include "lab_m1/tema1/Shape.h"
#include "lab_m1/tema1/Square.h"
#include "lab_m1/tema1/Romb.h"
#include "lab_m1/tema1/Hexagon.h"
#include "lab_m1/tema1/Star.h"
#include <stdlib.h>
#include <chrono>
#include <thread>


namespace m1 {
    class Tema1 : public gfxc::SimpleScene {
    public:
        Tema1();

        ~Tema1();

        void Init() override;

    private:
        void FrameStart() override;

        void Update(float deltaTimeSeconds) override;

        void FrameEnd() override;

        void OnInputUpdate(float deltaTime, int mods) override;

        void OnKeyPress(int key, int mods) override;

        void OnKeyRelease(int key, int mods) override;

        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;

        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;

        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;

        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;

        //bool CheckCollision(float c1_x, float c1_y, float c1_radius, float c2_x, float c2_y, float c2_radius);
        void OnWindowResize(int width, int height) override;

        glm::vec3 findColor(int choosed_romb);

        float getLocRand(int rand);

        int getNrStarsPerRomb(int type);

        bool collision(float c1_x, float c1_y, float c1_radius, float c2_x, float c2_y, float c2_radius);

        void cursorPositionCallback(WindowObject *window, int mouseX, int mouseY);


    protected:
        //float cx, cy;
        vector<Square> greenSquares;
        vector<Square> upSquares;
        vector<Romb> upRombs;
        vector<Romb *> tableRombs;
        vector<Star *> tableStars;
        vector<Star *> contorStars;
        vector<Romb *> copyTableRombs;
        vector<Hexagon *> tableHexagons;
        vector<Romb *> disparitieRomb;
        vector<Hexagon *> disparitieHex;


        float romb_len = 37.5f;
        float hexa_length = 50;
        int NO_STARS;
        int NO_LIVES;
        float star_x;
        float star_y;
        float btn_x_update, btn_y_update;
        float btn_x_release, btn_y_release;


        glm::mat3 modelMatrix = glm::mat3(1);
        glm::vec3 corner = glm::vec3(0, 0, 0);



        double timeForHex;
        double timeForStar;

        float mini_length = 10;
        float green_squareSide = 120;
        float red_squareSide = 50;
        int choosed_romb;
        int mouse_X, mouse_Y;

        // culori:
        glm::vec3 orange_color = glm::vec3(0.8, 0.4, 0);
        glm::vec3 blue_color = glm::vec3(0.2, 0.6, 1);
        glm::vec3 yellow_color = glm::vec3(1, 1, 0.6);
        glm::vec3 purple_color = glm::vec3(0.8, 0.6, 1);

        glm::vec3 grey_color = glm::vec3(0.75, 0.75, 0.75);
        glm::vec3 black_color = glm::vec3(0, 0, 0);
        glm::vec3 green_color = glm::vec3(0, 0.4f, 0);
        glm::vec3 red_color = glm::vec3(0.8f, 0, 0);


    };
}   // namespace m1