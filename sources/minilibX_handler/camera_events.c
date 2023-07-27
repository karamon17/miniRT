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
		move_vector(data->camera->origin,data->movement->up);
	else if (keycode == KEY_DOWN_ARROW)
        move_vector(data->camera->origin, data->movement->down);
	else if (keycode == KEY_LEFT_ARROW)
		move_vector(data->camera->origin, data->movement->left);
    else if (keycode == KEY_RIGHT_ARROW)
        move_vector(data->camera->origin, data->movement->right);
    else if ( keycode == KEY_PLUS)
        move_vector(data->camera->origin, data->movement->forward);
    else if (keycode == KEY_MINUS)
        move_vector(data->camera->origin, data->movement->backward);
   }


