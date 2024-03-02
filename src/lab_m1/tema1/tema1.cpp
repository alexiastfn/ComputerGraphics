#include "lab_m1/tema1/tema1.h"

#include <vector>
#include <iostream>
#include <random>


using namespace std;
using namespace m1;


Square *square_1;
Square *square_2;
Square *square_3;
Square *square_redzone;
Star *star_1;
Star *star_2;
Star *star_3;
Star *star_4;
Romb *romb_1;
Romb *romb_2;
Romb *romb_3;
Romb *romb_4;

Hexagon *hex_1;
Hexagon *hex_2;
Hexagon *hex_3;
Hexagon *hex_4;
Hexagon *hex_mic;


/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */


Tema1::Tema1() {
}


Tema1::~Tema1() {
}


void Tema1::Init() {
    glm::ivec2 resolution = window->GetResolution();
    auto camera = GetSceneCamera();
    camera->SetOrthographic(0, (float) resolution.x, 0, (float) resolution.y, 0.01f, 400);
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);

    timeForHex = 0;
    timeForStar = 0;

    srand(time(NULL));

    NO_LIVES = 3;
    NO_STARS = 10;

    star_x = 700;
    star_y = 550;

    square_redzone = new Square("square_redzone", corner, red_squareSide, red_color, 0, true);
    Mesh *square_redzone = square_1->createMySquare("square_redzone", corner, red_squareSide, red_color, 0, true);
    AddMeshToList(square_redzone);

    square_1 = new Square("square1", corner, red_squareSide, red_color, 0, true);
    Mesh *square1 = square_1->createMySquare("square1", corner, red_squareSide, red_color, 0, true);
    AddMeshToList(square1);

    square_2 = new Square("square2", corner, green_squareSide, green_color, 0, true);
    Mesh *square2 = square_1->createMySquare("square2", corner, green_squareSide, green_color, 0, true);
    AddMeshToList(square2);

    star_1 = new Star("star1", corner, mini_length, orange_color, 1, true);
    Mesh *star1 = star_1->createMyStar("star1", corner, mini_length, orange_color, 2, true);
    AddMeshToList(star1);

    star_2 = new Star("star2", corner, mini_length, blue_color, 1, true);
    Mesh *star2 = star_1->createMyStar("star2", corner, mini_length, blue_color, 2, true);
    AddMeshToList(star2);

    star_3 = new Star("star3", corner, mini_length, yellow_color, 2, true);
    Mesh *star3 = star_1->createMyStar("star3", corner, mini_length, yellow_color, 2, true);
    AddMeshToList(star3);

    star_4 = new Star("star4", corner, mini_length, purple_color, 2, true);
    Mesh *star4 = star_1->createMyStar("star4", corner, mini_length, purple_color, 1, true);
    AddMeshToList(star4);

    Mesh *star_life = star_1->createMyStar("star_life", corner, mini_length, grey_color, 1, true);
    AddMeshToList(star_life);


    square_3 = new Square("square3", corner, green_squareSide, black_color, 0, false);
    Mesh *square3 = square_1->createMySquare("square3", corner, green_squareSide, black_color, 0, false);
    AddMeshToList(square3);

    romb_1 = new Romb("romb1", corner, 0.75f * red_squareSide, orange_color, 2.0f, true);
    Mesh *romb1 = romb_1->createMyRomb("romb1", corner, 0.75f * red_squareSide, orange_color, 2.0f, true);
    AddMeshToList(romb1);

    romb_2 = new Romb("romb2", corner, 0.75f * red_squareSide, blue_color, 2.0f, true);
    Mesh *romb2 = romb_1->createMyRomb("romb2", corner, 0.75f * red_squareSide, blue_color, 2.0f, true);
    AddMeshToList(romb2);

    romb_3 = new Romb("romb3", corner, 0.75f * red_squareSide, yellow_color, 2.0f, true);
    Mesh *romb3 = romb_1->createMyRomb("romb3", corner, 0.75f * red_squareSide, yellow_color, 2.0f, true);
    AddMeshToList(romb3);

    romb_4 = new Romb("romb4", corner, 0.75f * red_squareSide, purple_color, 2.0f, true);
    Mesh *romb4 = romb_1->createMyRomb("romb4", corner, 0.75f * red_squareSide, purple_color, 2.0f, true);
    AddMeshToList(romb4);

    hex_1 = new Hexagon("hex1", corner, hexa_length, orange_color, 1.0f, true);
    Mesh *hex1 = hex_1->CreateMyFullHexa("hex1", corner, corner, hexa_length, hexa_length * 0.65f, orange_color,
                                         black_color, 1.0f, true);
    AddMeshToList(hex1);

    hex_2 = new Hexagon("hex2", corner, hexa_length, blue_color, 1.0f, true);
    Mesh *hex2 = hex_2->CreateMyFullHexa("hex2", corner, corner, hexa_length, hexa_length * 0.65f, blue_color,
                                         black_color, 1.0f, true);
    AddMeshToList(hex2);

    hex_3 = new Hexagon("hex3", corner, hexa_length, yellow_color, 1.0f, true);
    Mesh *hex3 = hex_2->CreateMyFullHexa("hex3", corner, corner, hexa_length, hexa_length * 0.65f, yellow_color,
                                         black_color, 1.0f, true);
    AddMeshToList(hex3);

    hex_4 = new Hexagon("hex4", corner, hexa_length, purple_color, 1.0f, true);
    Mesh *hex4 = hex_2->CreateMyFullHexa("hex4", corner, corner, hexa_length, hexa_length * 0.65f, purple_color,
                                         black_color, 1.0f, true);
    AddMeshToList(hex4);

}


void Tema1::FrameStart() {
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0.25f, 0.25f, 0.25f, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    GLsizei width = resolution.x;
    GLsizei height = resolution.y;
    glViewport(0, 0, resolution.x, resolution.y);
}


void Tema1::Update(float deltaTimeSeconds) {

    timeForHex += deltaTimeSeconds * 2;
    timeForStar += deltaTimeSeconds * 2;

    // SCENA DE JOC:

    square_redzone->location[0][0] = 20;
    square_redzone->location[0][1] = 50;
    RenderMesh2D(meshes["square_redzone"], shaders["VertexColor"],
                 square_redzone->DrawRedZone(square_redzone->location[0][0], square_redzone->location[0][1]));

    int green_x = 150;
    int green_y = 50;
    for (int j = 0; j < 3; j++) {

        for (int i = 0; i < 3; i++) {
            Square *aux_sq = new Square("square2", corner, green_squareSide, green_color, 0, true);
            RenderMesh2D(meshes["square2"], shaders["VertexColor"], aux_sq->DrawGreenSquare(green_x, green_y));
            aux_sq->location[0][0] = green_x;
            aux_sq->location[0][1] = green_y;

            green_y += green_squareSide + 30;
            greenSquares.push_back(*aux_sq);
        }
        green_x += green_squareSide + 30;
        green_y = 50;
    }

    for (int i = 0; i < NO_STARS; i++) {
        Star *aux_star = new Star("star_life", corner, mini_length, grey_color, 1, true);
        aux_star->location[0][0] = star_x;
        aux_star->location[0][1] = star_y;
        contorStars.push_back(aux_star);
        star_x += 2.2f * mini_length;
    }

    // PATRATE SUS:

    float black_x = 20 - 5;
    float black_y = 600 + 40;
    for (int i = 0; i < 4; i++) {
        Square *aux_sq = new Square("square2", corner, green_squareSide, green_color, 0, false);
        RenderMesh2D(meshes["square3"], shaders["VertexColor"], aux_sq->DrawGreenSquare(black_x, black_y));
        black_x += green_squareSide + 30;
        aux_sq->location[0][0] = black_x;
        aux_sq->location[0][1] = black_y;
        upSquares.push_back(*aux_sq);
    }

    // ROMB:

    int up_rb_x = 70;
    int up_rb_y = 700;

    for (int i = 0; i < 4; i++) {
        int nr = i + 1;
        Romb *aux_rb = new Romb("romb" + to_string(i + 1), corner, 0.75f * red_squareSide, orange_color, 1, true);
        aux_rb->location[0][0] = up_rb_x;
        aux_rb->location[0][1] = up_rb_y;
        upRombs.push_back(*aux_rb);
        RenderMesh2D(meshes["romb" + to_string(i + 1)], shaders["VertexColor"], aux_rb->DrawRomb(up_rb_x, up_rb_y));

        if (nr == 1) {
            RenderMesh2D(meshes["star_life"], shaders["VertexColor"],
                         star_1->DrawStar(up_rb_x, up_rb_y - green_squareSide));
        } else if (nr == 2) {
            RenderMesh2D(meshes["star_life"], shaders["VertexColor"],
                         star_1->DrawStar(up_rb_x, up_rb_y - green_squareSide));
            RenderMesh2D(meshes["star_life"], shaders["VertexColor"],
                         star_1->DrawStar(up_rb_x + 20, up_rb_y - green_squareSide));

        } else if (nr == 3) {
            RenderMesh2D(meshes["star_life"], shaders["VertexColor"],
                         star_1->DrawStar(up_rb_x, up_rb_y - green_squareSide));
            RenderMesh2D(meshes["star_life"], shaders["VertexColor"],
                         star_1->DrawStar(up_rb_x + 20, up_rb_y - green_squareSide));

        } else if (nr == 4) {
            RenderMesh2D(meshes["star_life"], shaders["VertexColor"],
                         star_1->DrawStar(up_rb_x, up_rb_y - green_squareSide));
            RenderMesh2D(meshes["star_life"], shaders["VertexColor"],
                         star_1->DrawStar(up_rb_x + 20, up_rb_y - green_squareSide));
            RenderMesh2D(meshes["star_life"], shaders["VertexColor"],
                         star_1->DrawStar(up_rb_x + 20 + 20, up_rb_y - green_squareSide));

        }
        up_rb_x += green_squareSide + 30;
    }

    // APARITIE RANDOM HEXAGON:

    float x_hex_start = 2500;
    int randColor;
    double aux_timeHex = glfwGetTime();
    double dif = aux_timeHex - timeForHex;
    int randomTime = rand() % 10 + 7;   // intre 7-10 sec

    if (-dif > randomTime) {

        int randGreenSquare = rand() % 3 + 1;
        randColor = rand() % 4 + 1;

        glm::vec3 hex_color = findColor(randColor);
        float y_hex_start = getLocRand(randGreenSquare);

        Hexagon *aux_hex = new Hexagon("hex" + to_string(randColor), corner, hexa_length, hex_color, 1, true);
        aux_hex->nrRand = randGreenSquare;
        aux_hex->type = randColor;
        aux_hex->aTrecutDeREDZONE = false;
        aux_hex->location[0][0] = x_hex_start;
        aux_hex->location[0][1] = y_hex_start + 60;
        tableHexagons.push_back(aux_hex);

        timeForHex = glfwGetTime();
    }

    // FOR HEXAGON { FOR ROMB }

    for (int i = 0; i < tableHexagons.size(); i++) {

        Hexagon *hex = tableHexagons[i];
        hex->modelMatrix = hex->DrawMovingHexP1(hex->location[0][0], hex->location[0][1],
                                                hex->translateX_hex,
                                                hex->translateY_hex);

        float delta = 100 * deltaTimeSeconds;
        hex->translateX_hex -= delta;
        hex->location[0][0] -= delta;

        if (!hex->collisionHappened) {
            RenderMesh2D(meshes["hex" + to_string(hex->type)], shaders["VertexColor"], hex->modelMatrix);
        }

        if (NO_LIVES == 0) {
            perror("</3 no more lives! end game </3");
            exit(1);
        }

        if (hex->location[0][0] < 1200 && !hex->collisionHappened) {
            NO_LIVES -= 1;
            hex->aTrecutDeREDZONE = true;
            tableHexagons.erase(tableHexagons.begin() + i);
            break;

        }

        for (int r = 0; r < tableRombs.size(); r++) {

            Romb *romb = tableRombs[r];
            if (!romb->collisionHappened) {
                RenderMesh2D(meshes["romb" + to_string(romb->type)], shaders["VertexColor"], romb->modelMatrix);
            }


            if (romb->nrRand == hex->nrRand && romb->type == hex->type && !hex->aTrecutDeREDZONE) {

                Star *star = romb->tableStars_romb[0];
                star->movingStarAnimation = star->StarAnimation(star, deltaTimeSeconds);
                RenderMesh2D(meshes["star" + to_string(star->type)], shaders["VertexColor"], star->movingStarAnimation);

                if (collision(hex->location[0][0] + hex->translateX_hex,
                              hex->location[0][1] + hex->translateY_hex, hexa_length,
                              star->location[0][0] + star->translateX_star,
                              star->location[0][1] + star->translateY_star,
                              mini_length)) {
                    hex->collisionHappened = true;
                    disparitieHex.push_back(hex);
                }

                if (collision(romb->location[0][0], romb->location[0][1], romb_len,
                              hex->location[0][0] + hex->translateX_hex,
                              hex->location[0][1] + hex->translateY_hex, hexa_length)
                    && !hex->collisionHappened) {
                    romb->collisionHappened = true;
                    disparitieRomb.push_back(romb);
                }
            }
        }
    }

    // vector DISPARITIE HEXAGON:

    if (!disparitieHex.empty()) {
        auto it = disparitieHex.begin();
        while (it != disparitieHex.end()) {
            Hexagon *hex = *it;
            hex->collisionHappened = true;
            hex->modelMatrix = glm::mat3(1);
            hex->modelMatrix *= transform2D::Translate(hex->location[0][0] + hex->translateX_hex + mini_length,
                                                       hex->location[0][1] + hex->translateY_hex);

            if (hex->disp_sx > 0) {
                hex->disp_sx -= 0.5f * deltaTimeSeconds;
            }

            if (hex->disp_sy > 0) {
                hex->disp_sy -= 0.5f * deltaTimeSeconds;
            }

            hex->modelMatrix *= transform2D::Scale(hex->disp_sx, hex->disp_sy);
            RenderMesh2D(meshes["hex" + to_string(hex->type)], shaders["VertexColor"], hex->modelMatrix);

            if (hex->disp_sx <= 5.0f || hex->disp_sy <= 5.0f) {
                disparitieHex.pop_back();
            } else {
                ++it;
            }
        }
    }

    // vector DISPARITIE ROMB:

    if (!disparitieRomb.empty()) {
        int i = -1;
        auto it = disparitieRomb.begin();
        while (it != disparitieRomb.end()) {
            Romb *romb = *it;
            i++;
            romb->collisionHappened = true;
            romb->modelMatrix = glm::mat3(1);
            romb->modelMatrix *= transform2D::Translate(romb->location[0][0], romb->location[0][1]);


            if (romb->disp_sx > 0) {
                romb->disp_sx -= 0.5f * deltaTimeSeconds;
            }

            if (romb->disp_sy > 0) {
                romb->disp_sy -= 0.5f * deltaTimeSeconds;
            }

            romb->modelMatrix *= transform2D::Scale(romb->disp_sx, romb->disp_sy);
            RenderMesh2D(meshes["romb" + to_string(romb->type)], shaders["VertexColor"], romb->modelMatrix);

            if (romb->disp_sx <= 5.0f || romb->disp_sy <= 5.0f) {
                disparitieRomb.pop_back();
            } else {
                ++it;
            }
        }
    }

    // patrate rosii: - NR of LIVES

    int red_x = 700;
    int red_y = 600;

    for (int i = 0; i < NO_LIVES; i++) {

        modelMatrix = square_redzone->DrawGreenSquare(red_x, red_y);
        RenderMesh2D(meshes["square1"], shaders["VertexColor"],
                     modelMatrix);
        red_x += 75;
    }


    for (int i = 0; i < NO_STARS; i++) {
        RenderMesh2D(meshes["star_life"], shaders["VertexColor"],
                     contorStars[i]->DrawStar(contorStars[i]->location[0][0], contorStars[i]->location[0][1]));
    }

    for (int c = 0; c < copyTableRombs.size(); c++) {
        Romb *aux = copyTableRombs[c];
        NO_STARS -= getNrStarsPerRomb(aux->type);
//        if(NO_STARS <= 0) {
//            perror("no more resources. try again! </3");
//            exit(1);
//        }
        for (int s = 0; s < getNrStarsPerRomb(aux->type); s++) {
            contorStars.erase(contorStars.end() - 1 - c);
        }
        copyTableRombs.erase(copyTableRombs.begin() + c);
    }


}


void Tema1::FrameEnd() {
}

/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void Tema1::OnInputUpdate(float deltaTime, int mods) {
}


void Tema1::OnKeyPress(int key, int mods) {
    // Add key press event
}


void Tema1::OnKeyRelease(int key, int mods) {
    // Add key release event
}


void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) {
    // Add mouse move event
}


void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) {

    mouseY = 720 - mouseY;
    mouse_Y = 720 - mouse_Y;

    if (button == 1) {

        if (mouseY >= 320 && mouseY <= 380) {

            if (mouseX >= 10 && mouseX <= 70) {
                choosed_romb = 1;
            } else if (mouseX >= 85 && mouseX <= 145) {
                choosed_romb = 2;
            } else if (mouseX >= 160 && mouseX <= 220) {
                choosed_romb = 3;
            } else if (mouseX >= 230 && mouseX <= 295) {
                choosed_romb = 4;

            }
        }

    }

}


void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) {

    mouseY = 720 - mouseY;
    mouse_Y = 720 - mouse_Y;
    int rand, coloana;

    if (button == 1) {

        if (mouseX >= 75 && mouseX <= 135) {
            // prima coloana
            btn_x_release = 75;
            btn_x_update = 150;
            coloana = 1;

            if (mouseY >= 720 - 692 && mouseY <= 720 - 630) {
                btn_y_release = 720 - 692;
                btn_y_update = 50;
                rand = 1;

            } else if (mouseY >= 720 - 618 && mouseY <= 720 - 560) {
                btn_y_release = 720 - 618;
                btn_y_update = 200;
                rand = 2;

            } else if (mouseY >= 720 - 545 && mouseY <= 720 - 485) {
                btn_y_release = 720 - 545;
                btn_y_update = 350;
                rand = 3;
            }

        } else if (mouseX >= 150 && mouseX <= 210) {
            // a doua coloana
            btn_x_release = 150;
            btn_x_update = 300;
            coloana = 2;

            if (mouseY >= 720 - 692 && mouseY <= 720 - 630) {
                btn_y_release = 720 - 692;
                btn_y_update = 50;
                rand = 1;

            } else if (mouseY >= 720 - 618 && mouseY <= 720 - 560) {
                btn_y_release = 720 - 618;
                btn_y_update = 200;
                rand = 2;

            } else if (mouseY >= 720 - 545 && mouseY <= 720 - 485) {
                btn_y_release = 720 - 545;
                btn_y_update = 350;
                rand = 3;

            }


        } else if (mouseX >= 225 && mouseX <= 285) {
            // a treia coloana
            btn_x_release = 225;
            btn_x_update = 450;
            coloana = 3;

            if (mouseY >= 720 - 692 && mouseY <= 720 - 630) {
                btn_y_release = 720 - 692;
                btn_y_update = 50;
                rand = 1;

            } else if (mouseY >= 720 - 618 && mouseY <= 720 - 560) {
                btn_y_release = 720 - 618;
                btn_y_update = 200;
                rand = 2;

            } else if (mouseY >= 720 - 545 && mouseY <= 720 - 485) {
                btn_y_release = 720 - 545;
                btn_y_update = 350;
                rand = 3;
                //btn_y_update = 320;
            }

        }

    }

    Romb *aux_romb = new Romb("romb" + to_string(choosed_romb), corner, romb_len, findColor(choosed_romb), 1, true);
    aux_romb->type = choosed_romb;
    aux_romb->nrRand = rand;
    aux_romb->nrColoana = coloana;
    aux_romb->btn_x_update = btn_x_update;
    aux_romb->location[0][0] = btn_x_update + 0.5f * green_squareSide;
    aux_romb->location[0][1] = btn_y_update + 0.5f * green_squareSide;
    aux_romb->NO_STARS = getNrStarsPerRomb(aux_romb->type);
    aux_romb->modelMatrix = aux_romb->DrawRomb(aux_romb->location[0][0], aux_romb->location[0][1]);
    tableRombs.push_back(aux_romb);
    copyTableRombs.push_back(aux_romb);


    for (int i = 0; i < 3; i++) {
        Star *s = new Star("star_pr" + to_string(aux_romb->type), corner, mini_length, findColor(choosed_romb), 1,
                           true);
        s->type = aux_romb->type;
        s->nrRand = aux_romb->nrRand;
        s->btn_x_update = btn_x_update;
        s->location[0][0] = btn_x_update + 2.25f * red_squareSide;
        s->location[0][1] = btn_y_update + red_squareSide;
        aux_romb->tableStars_romb.push_back(s);

    }


}


void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) {


}


void Tema1::OnWindowResize(int width, int height) {
}

glm::vec3 Tema1::findColor(int choosed_romb) {

    if (choosed_romb == 1)
        return glm::vec3(0.8, 0.4, 0);
    if (choosed_romb == 2)
        return glm::vec3(0.2, 0.6, 1);
    if (choosed_romb == 3)
        return glm::vec3(1, 1, 0.6);
    if (choosed_romb == 4)
        return glm::vec3(0.8, 0.6, 1);

}


float Tema1::getLocRand(int rand) {

    // return coord y

    if (rand == 3) {
        return 350;
    } else if (rand == 2) {
        return 200;
    } else if (rand == 1) {
        return 50;
    }

}

int Tema1::getNrStarsPerRomb(int type) {


    if (type == 3) {
        return 2;
    } else if (type == 2) {
        return 2;
    } else if (type == 1) {
        return 1;
    } else if (type == 4) {
        return 3;
    }

}

bool Tema1::collision(float c1_x, float c1_y, float c1_radius, float c2_x, float c2_y, float c2_radius) {

    float distanceX = c1_x - c2_x;
    float distanceY = c1_y - c2_y;
    float eq_1 = sqrt(distanceX * distanceX + distanceY * distanceY);

    float eq_2 = c1_radius + c2_radius;

    return (eq_1 < eq_2);
}

