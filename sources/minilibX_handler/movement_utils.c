#include "../includes/miniRT.h"

void rotate_quaternion(t_vector *light, t_quaternion *direction) {
    t_quaternion *light_direction_q;
    t_quaternion rotation_conjugate;
    t_quaternion new_direction;

    light_direction_q = quaternion_new(0, light->x, light->y, light->z);
    rotation_conjugate = conjugate(*direction);
    new_direction = multiply_quaternion(multiply_quaternion(*direction, *light_direction_q), rotation_conjugate);
    quaternion_normalize(new_direction);
    light->x = new_direction.x;
    light->y = new_direction.y;
    light->z = new_direction.z;
}

void move_vector(t_vector *light, t_vector *direction) {
    light->x += direction->x;
    light->y += direction->y;
    light->z += direction->z;
}