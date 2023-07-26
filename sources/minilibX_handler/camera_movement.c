#include "../../includes/miniRT.h"

t_quaternion rotated_direction_quaternion(t_quaternion camera, t_quaternion rotation, t_quaternion rotation_conjugate);

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

void rotate_cam(t_data *data) {

	t_vector axis;
	axis.x = 0;
	axis.y = 1;
	axis.z = 0;

	float theta = 30 * 0.5f;
	t_quaternion rotation;
	rotation.w = cos(theta);
	rotation.x = axis.x * sin(theta);
	rotation.y = axis.z * sin(theta);
	rotation.z = axis.z * sin(theta);



	t_quaternion dir_quat;
	dir_quat.w = 0;
	dir_quat.x = data->camera->direction->x;
	dir_quat.y = data->camera->direction->y;
	dir_quat.z = data->camera->direction->z;

    t_quaternion rotation_conjugate = conjugate(rotation);

    t_quaternion result = multiply_quaternion(multiply_quaternion(rotation, dir_quat), rotation_conjugate);
	(void ) result;
	// Update the dir_quat's orientation
    data->camera->direction->x += 10;
    data->camera->direction->y += 10;
    data->camera->direction->z = -1;
	ray_trace(data->mlx_data->mlx, data);
}


t_quaternion multiply_quaternion(t_quaternion q1, t_quaternion q2) {
    t_quaternion result;

	result.w = q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;
	result.x = q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y;
	result.y = q1.w * q2.y - q1.x * q2.z + q1.y * q2.w + q1.z * q2.x;
	result.z = q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w;
	return result;
}
