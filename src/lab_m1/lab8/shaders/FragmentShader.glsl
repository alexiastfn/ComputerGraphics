#version 330

// Input
in vec3 world_position;
in vec3 world_normal;

// Uniforms for light properties
uniform vec3 light_direction;
//uniform vec3 light_position;
uniform vec3 eye_position;

uniform float material_kd;
uniform float material_ks;
uniform int material_shininess;

// TODO(student): Declare any other uniforms
uniform vec3 object_color;
uniform int type_of_light;
uniform float cut_off_angle;

uniform vec3 point_light_pos[2];
uniform vec3 point_light_color[2];

// Output
layout(location = 0) out vec4 out_color;

vec3 point_light_contribution(vec3 light_pos, vec3 light_color);

void main()
{
    vec3 result = point_light_contribution(point_light_pos[0], object_color) + point_light_contribution(point_light_pos[1], object_color);

    // TODO(student): Write pixel out color
    out_color = vec4(result, 1);

}

vec3 point_light_contribution(vec3 light_pos, vec3 light_color)
{
    vec3 N = normalize(world_normal);
    vec3 L = normalize(light_pos - world_position);
    vec3 V = normalize(eye_position - world_position);
    vec3 H = normalize(L + V);

    // TODO(student): Define ambient, diffuse and specular light components
    float ambient_light = 0.25;
    float diffuse_light = material_kd * max(dot(normalize(N), L), 0);
    float specular_light = 0;
    float d = distance(light_pos, world_position);
    float atenuare_factor = 1/ (d * d);

    if (diffuse_light > 0)
    {
        specular_light = material_ks * pow(max(dot(normalize(N), H), 0), material_shininess);
    }

    float light = 0;

    if (type_of_light == 1)
    {
        float cut_off_rad		= radians(cut_off_angle);
        float spot_light		= dot(-L, light_direction);
        float spot_light_limit	= cos(cut_off_rad);

        if (spot_light > spot_light_limit)
        {
            float linear_att		= (spot_light - spot_light_limit) / (1 - spot_light_limit);
            float light_att_factor	= pow(linear_att, 2);
            light					= ambient_light + light_att_factor * atenuare_factor * (diffuse_light + specular_light);
        } else
        {
            light = ambient_light;
        }
    } else {
        light = ambient_light + atenuare_factor * (diffuse_light + specular_light);
    }

    vec3 color = light_color * light;
    return color;
}
