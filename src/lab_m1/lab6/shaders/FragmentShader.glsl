#version 330

// Input
// TODO(student): Get values from vertex shader
in vec3 frag_position;
in vec3 frag_normal;
in vec2 frag_texture;
in vec3 frag_color;

// Output
//layout(location = 0) out vec3 v_position;
//layout(location = 3) out vec3 v_normal;
//layout(location = 2) out vec2 v_texture;
//layout(location = 1) out vec3 v_color;



//layout(location = 0) out vec3 out_normal;
//layout(location = 1) out vec2 out_texture;
layout(location = 0) out vec3 out_color;





void main()
{
    // TODO(student): Write pixel out color
    out_color = vec3(frag_color);


    //out_color = vec4(frag_normal, 1);

//      out_normal	= vec3(frag_normal);
//    out_texture = vec2(frag_texture);

}
