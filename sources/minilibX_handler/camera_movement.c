#include "../../includes/miniRT.h"

t_quaternion conjugate(t_quaternion q) {
	t_quaternion result;
	result.w = q.w;
	result.x = -q.x;
	result.y = -q.y;
	result.z = -q.z;
	return result;
}

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

void quaternion_normalize(t_quaternion quaternion) {
	float magnitude;

	magnitude = sqrtf(quaternion.w * quaternion.w + quaternion.x * quaternion.x + quaternion.y * quaternion.y + quaternion.z * quaternion.z);
	quaternion.w /= magnitude;
	quaternion.x /= magnitude;
	quaternion.y /= magnitude;
	quaternion.z /= magnitude;

}


t_quaternion multiply_quaternion(t_quaternion q1, t_quaternion q2) {
    t_quaternion result;

	result.w = q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;
	result.x = q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y;
	result.y = q1.w * q2.y - q1.x * q2.z + q1.y * q2.w + q1.z * q2.x;
	result.z = q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w;
	return result;
}
