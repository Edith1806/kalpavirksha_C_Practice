#include<stdio.h>
#define PI 3.14

float calculate_volume_of_sphere(float radius)
{
    float radius_cube = radius * radius * radius;
    float volume = (4/3.0) * PI * radius_cube;
    return volume;
}

int main(void)
{
    float radius;
    scanf("%f",&radius);
    printf("Volume of Sphere is %.2f", calculate_volume_of_sphere(radius));
    return 0;
}