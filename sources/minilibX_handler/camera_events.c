#include "../../includes/miniRT.h"

void rotate_camera(t_data *data, t_quaternion *direction);

void rotate_figure_for_camera(t_data *data, t_figure *figure, t_quaternion *direction);

void move_camera(t_data *data, t_vector *direction);

void move_figure_for_camera(t_figure *figure, t_vector *direction, int is_positive);

void press_camera_rotation_keys(int keycode, t_data *data) {
	if (keycode == KEY_1)
		rotate_camera(data, data->movement->rotate_y_right);
	else if (keycode == KEY_3)
		rotate_camera(data, data->movement->rotate_y_left);
	else if (keycode == KEY_5)
		rotate_camera(data, data->movement->rotate_x_right);
	else if (keycode == KEY_2)
		rotate_camera(data, data->movement->rotate_x_left);
}

t_vector quaternion_rotate_point(t_quaternion q, t_vector point) {
	t_vector result;

	float t2 = q.w * q.x;
	float t3 = q.w * q.y;
	float t4 = q.w * q.z;
	float t5 = -q.x * q.x;
	float t6 = q.x * q.y;
	float t7 = q.x * q.z;
	float t8 = -q.y * q.y;
	float t9 = q.y * q.z;
	float t10 = -q.z * q.z;

	result.x = 2.0f * (t8 + t10) * point.x + 2.0f * (t6 - t4) * point.y + 2.0f * (t3 + t7) * point.z + point.x;
	result.y = 2.0f * (t4 + t6) * point.x + 2.0f * (t5 + t10) * point.y + 2.0f * (t9 - t2) * point.z + point.y;
	result.z = 2.0f * (t7 - t3) * point.x + 2.0f * (t2 + t9) * point.y + 2.0f * (t5 + t8) * point.z + point.z;

	return result;
}

void rotate_camera(t_data *data, t_quaternion *direction) {

	t_figure *figure;

	figure = data->figures;

	while(figure)
	{
		rotate_figure_for_camera(data, figure, direction);
		figure = figure->next;
	}
	return ;
}

void rotate_figure_for_camera(t_data *data, t_figure *figure, t_quaternion *direction) {

	t_vector rotation_point = *data->camera->origin;
	t_vector *object_position = NULL;
	object_position = figure->center;
	if(figure->type == PLANE)
		object_position = figure->figure_body.plane.normal;

	t_vector rotation_axis = {object_position->x - rotation_point.x, object_position->y - rotation_point.y, object_position->z - rotation_point.z};
	float length = sqrtf(rotation_axis.x * rotation_axis.x + rotation_axis.y * rotation_axis.y + rotation_axis.z * rotation_axis.z);
	rotation_axis.x /= length;
	rotation_axis.y /= length;
	rotation_axis.z /= length;

	object_position->x -= rotation_point.x;
	object_position->y -= rotation_point.y;
	object_position->z -= rotation_point.z;

	rotate_quaternion(object_position, direction);

	object_position->x += rotation_point.x;
	object_position->y += rotation_point.y;
	object_position->z += rotation_point.z;
}

void press_camera_movement_keys(int keycode, t_data *data) {

	if (keycode == KEY_UP_ARROW)
		move_camera(data, data->camera->up_vector);
	else if (keycode == KEY_DOWN_ARROW)
        move_vector(data->camera->origin, data->camera->up_vector, 1);
	else if (keycode == KEY_LEFT_ARROW)
		move_vector(data->camera->origin, data->camera->right_vector, 1);
    else if (keycode == KEY_RIGHT_ARROW)
        move_vector(data->camera->origin, data->camera->right_vector, 0);
    else if ( keycode == KEY_PLUS)
        move_vector(data->camera->origin, data->camera->direction, 1);
    else if (keycode == KEY_MINUS)
        move_vector(data->camera->origin, data->camera->direction, 0);
   }

void move_camera(t_data *data, t_vector *direction) {
	t_figure *figure;

	figure = data->figures;
	while (figure) {
		move_figure_for_camera(figure, direction, 1);
		figure = figure->next;
	}
}

void move_figure_for_camera(t_figure *figure, t_vector *direction, int is_positive) {
	t_vector *object_position = NULL;
	object_position = figure->center;

	if(!is_positive)
	{
		object_position->x += direction->x;
		object_position->y += direction->y;
		object_position->z += direction->z;
	}
	else
	{
		object_position->x -= direction->x;
		object_position->y -= direction->y;
		object_position->z -= direction->z;
	}
}


void work_with_camera(int keycode, t_data *data) {

	if(is_camera_movement_key(keycode))
		press_camera_movement_keys(keycode, data);
	else if(is_camera_rotation_key(keycode))
		press_camera_rotation_keys(keycode, data);

}