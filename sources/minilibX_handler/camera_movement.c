#include "../../includes/miniRT.h"

void move_cam(t_data *data, t_vector *direction) {

    t_vector *new_origin;

    new_origin = add_vector(data->camera->origin, direction);
    free(data->camera->origin);
    data->camera->origin = new_origin;
}

void rotate_cam(t_data *data, t_quaternion *rotate_direction) {

	t_quaternion *camera_direction_q;
	t_quaternion rotation_conjugate;
	t_quaternion new_direction;

	camera_direction_q = quaternion_new(0, data->camera->direction->x, data->camera->direction->y, data->camera->direction->z);
	rotation_conjugate = conjugate(*rotate_direction);
	new_direction = multiply_quaternion(multiply_quaternion(*rotate_direction, *camera_direction_q), rotation_conjugate);
	quaternion_normalize(new_direction);
	data->camera->direction->x = new_direction.x;
	data->camera->direction->y = new_direction.y;
	data->camera->direction->z = new_direction.z;
}


