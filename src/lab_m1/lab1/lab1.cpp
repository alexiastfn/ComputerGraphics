#include "lab_m1/lab1/lab1.h"
#include "GLFW/glfw3.h"

#include <vector>
#include <iostream>

using namespace std;
using namespace m1;




/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */


Lab1::Lab1()
{
    // TODO(student): Never forget to initialize class variables!

}


Lab1::~Lab1()
{
}


void Lab1::Init()
{
    // Load a mesh from file into GPU memory. We only need to do it once,
    // no matter how many times we want to draw this mesh.
    z_pos = 0;
    {
        Mesh* mesh = new Mesh("box");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "box.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }

    // TODO(student): Load some more meshes. The value of RESOURCE_PATH::MODELS
    // is actually a path on disk, go there and you will find more meshes.
    {
        Mesh *my_mesh = new Mesh("sfera");
        my_mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "sphere.obj");
        meshes[my_mesh->GetMeshID()] = my_mesh;
    }

    {
        Mesh *my_mesh1 = new Mesh("teapot");
        my_mesh1->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "teapot.obj");
        meshes[my_mesh1->GetMeshID()] = my_mesh1;
    }

    {
        Mesh *my_mesh2 = new Mesh("bunny");
        my_mesh2->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "animals"), "bunny.obj");
        meshes[my_mesh2->GetMeshID()] = my_mesh2;
    }

    {
        Mesh *my_mesh3 = new Mesh("oil");
        my_mesh3->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "props"), "oildrum_center.obj");
        meshes[my_mesh3->GetMeshID()] = my_mesh3;
    }

    {
        Mesh *my_mesh4 = new Mesh("vegg");
        my_mesh4->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "vegetation"), "bamboo.obj");
        meshes[my_mesh4->GetMeshID()] = my_mesh4;
    }

}


void Lab1::FrameStart()
{
}


void Lab1::Update(float deltaTimeSeconds)
{
    glm::ivec2 resolution = window->props.resolution;

    // Sets the clear color for the color buffer

    // TODO(student): Generalize the arguments of `glClearColor`.
    // You can, for example, declare three variables in the class header,
    // that will store the color components (red, green, blue).
    glClearColor(my_red, my_green, my_blue, my_alpha);

    // Clears the color buffer (using the previously set color) and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);

    // Render the object
    RenderMesh(meshes["box"], glm::vec3(1, 0.5f, 0), glm::vec3(0.5f));

    // Render the object again but with different properties
    //z_pos += 0.5 * deltaTimeSeconds;
    //RenderMesh(meshes["box"], glm::vec3(-1, 0.5f, 0));
    RenderMesh(meshes["box"], glm::vec3(x_pos, y_pos, z_pos));

    // TODO(student): We need to render (a.k.a. draw) the mesh that
    // was previously loaded. We do this using `RenderMesh`. Check the
    // signature of this function to see the meaning of its parameters.
    // You can draw the same mesh any number of times.

    if(obj == "bunny") {
        RenderMesh(meshes[obj], glm::vec3(0.25, 0.4f, 0.60), glm::vec3(0.025f));
    } else if(obj == "oil") {
        RenderMesh(meshes[obj], glm::vec3(0.25, 0.4f, 0.2), glm::vec3(100));
    } else {
        RenderMesh(meshes[obj], glm::vec3(0.10, 0.4f, 0.75), glm::vec3(0.65f));
    }


    

}


void Lab1::FrameEnd()
{
    DrawCoordinateSystem();
}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void Lab1::OnInputUpdate(float deltaTime, int mods)
{
    // Treat continuous update based on input

    // TODO(student): Add some key hold events that will let you move
    // a mesh instance on all three axes. You will also need to
    // generalize the position used by `RenderMesh`.
    // if (window->KeyHold(GLFW_KEY_S))
    //     std::cout << "Alexia" << std::endl;


    if (window->KeyHold(GLFW_KEY_W)) {
        z_pos += 0.3f * deltaTime;
    }

    if (window->KeyHold(GLFW_KEY_S)) {
        z_pos += (-1) * 0.3f * deltaTime;
    }

    if (window->KeyHold(GLFW_KEY_A)) {
        x_pos += 0.3f * deltaTime;
    }

    if (window->KeyHold(GLFW_KEY_D)) {
        x_pos += (-1) * 0.3f * deltaTime;
    }

    if (window->KeyHold(GLFW_KEY_E)) {
        y_pos += 0.3f * deltaTime;
    }

    if (window->KeyHold(GLFW_KEY_Q)) {
        y_pos += (-1) * 0.3f * deltaTime;
    }

}


void Lab1::OnKeyPress(int key, int mods)
{
    // Add key press event
    if (key == GLFW_KEY_F) {
        // TODO(student): Change the values of the color components.
        
        my_red = my_red + 0.082f;
        my_blue = my_blue - 0.08f;
        my_green = my_green - 0.08f;
    
    }

    // TODO(student): Add a key press event that will let you cycle
    // through at least two meshes, rendered at the same position.
    // You will also need to generalize the mesh name used by `RenderMesh`.

    if(key == GLFW_KEY_R) {

       if(obj == "sfera") {
        obj = "teapot";
       }else if(obj == "teapot") {
        obj = "bunny";
       } else if(obj == "bunny") {
        obj = "oil";
       } else {
        obj = "sfera";
       }

       

    }
    





}


void Lab1::OnKeyRelease(int key, int mods)
{
    // Add key release event
}


void Lab1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    // Add mouse move event
}


void Lab1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button press event
}


void Lab1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
}


void Lab1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
    // Treat mouse scroll event
}


void Lab1::OnWindowResize(int width, int height)
{
    // Treat window resize event
}
