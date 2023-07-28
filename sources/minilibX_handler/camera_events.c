#include "../../includes/miniRT.h"


void press_camera_rotation_keys(int keycode, t_data *data) {
	if (keycode == KEY_1)
		rotate_quaternion(data->camera->direction, data->movement->rotate_y_left);
	else if (keycode == KEY_3)
		rotate_quaternion(data->camera->direction, data->movement->rotate_y_right);
	else if (keycode == KEY_5)
		rotate_quaternion(data->camera->direction, data->movement->rotate_x_left);
	else if (keycode == KEY_2)
		rotate_quaternion(data->camera->direction, data->movement->rotate_x_right);
}

void press_camera_movement_keys(int keycode, t_data *data) {

	if (keycode == KEY_UP_ARROW)
		move_vector(data->camera->origin, multiply_vector( 20 ,data->camera->up_vector));
	else if (keycode == KEY_DOWN_ARROW)
        move_vector(data->camera->origin, multiply_vector(-1,data->camera->up_vector));
	else if (keycode == KEY_LEFT_ARROW)
		move_vector(data->camera->origin, multiply_vector( 20 ,data->camera->right_vector));
    else if (keycode == KEY_RIGHT_ARROW)
        move_vector(data->camera->origin, multiply_vector( -20 ,data->camera->right_vector));
    else if ( keycode == KEY_PLUS)
        move_vector(data->camera->origin, multiply_vector(20,data->camera->direction));
    else if (keycode == KEY_MINUS)
        move_vector(data->camera->origin, multiply_vector(-20,data->camera->direction));
   }

t_vector *vector_cross_prodact(t_vector *vector1, t_vector *vector2) {
	t_vector *result;

	result = vector_new(0,0,0);
	result->x = vector1->y * vector2->z - vector1->z * vector2->y;
	result->y = vector1->z * vector2->x - vector1->x * vector2->z;
	result->z = vector1->x * vector2->y - vector1->y * vector2->x;
	return (result);
}


