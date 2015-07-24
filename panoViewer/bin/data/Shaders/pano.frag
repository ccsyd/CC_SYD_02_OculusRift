#version 330
#define M_PI 3.1415926535897932384626433832795

uniform mat4 modelViewProjectionMatrix; // automatically imported by OF
uniform mat4 modelViewMatrix; // automatically imported by OF
uniform mat4 normalMatrix; // the normal matrix (the inversed-then-transposed modelView matrix)
// uniform vec3 color;


uniform sampler2D pano;

in vec4 worldpos; // in local space
in vec4 worldnorm; // in local space

out vec4 fragColor;

float fitf(float value, float low1, float high1, float low2, float high2)
{
    return low2 + (value - low1) * (high2 - low2) / (high1 - low1);
}
void main()
{
    vec3 n = vec3(worldnorm.x,worldnorm.y,worldnorm.z);

    float theta = (atan(n.x,n.z) / M_PI)*0.5 + 0.5;
    theta = mod(theta + 0.5, 1.0);

    float phi = acos(n.y) / M_PI;
    phi = 1.0 - fitf(n.y,-1,1,0,1);
    //truephi = fitf(phi,-1,1,0,1);

    vec4 tc = texture(pano, vec2(theta, phi));
    fragColor = vec4(tc.r, tc.g, tc.b, 1.0);
}
