#include "../includes/miniRT.h"

void rotate_quaternion(t_vector *vector, t_quaternion *direction) {
    t_quaternion *direction_q;
    t_quaternion rotation_conjugate;
    t_quaternion new_direction;

    direction_q = quaternion_new(0, vector->x, vector->y, vector->z);
    rotation_conjugate = conjugate(*direction);
    new_direction = multiply_quaternion(multiply_quaternion(*direction, *direction_q), rotation_conjugate);
    quaternion_normalize(new_direction);
    vector->x = new_direction.x;
    vector->y = new_direction.y;
    vector->z = new_direction.z;
}

void move_vector(t_vector *vector, t_vector *direction, int direction_flag) {
	float speed;

	speed = 10;
	if (direction_flag == 0)
		speed *= -1;
    vector->x += direction->x * speed;
    vector->y += direction->y * speed;
    vector->z += direction->z * speed;
}