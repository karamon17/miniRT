#include "../../includes/miniRT.h"


void press_camera_rotation_keys(int keycode, t_data *data) {
	if (keycode == KEY_1)
		rotate_cam(data, data->movement->rotate_y_left);
	else if (keycode == KEY_3)
		rotate_cam(data, data->movement->rotate_y_right);
	else if (keycode == KEY_5)
		rotate_cam(data, data->movement->rotate_x_left);
	else if (keycode == KEY_2)
		rotate_cam(data, data->movement->rotate_x_right);
/*	else if (keycode == KEY_4)
		rotate_cam(data, data->movement->rotate_z_left);
	else if (keycode == KEY_6)
		rotate_cam(data, data->movement->rotate_z_right);*/
}

void press_camera_movement_keys(int keycode, t_data *data) {

	if (keycode == KEY_UP_ARROW)
		move_cam(data,data->movement->up);
	else if (keycode == KEY_DOWN_ARROW)
        move_cam(data, data->movement->down);
	else if (keycode == KEY_LEFT_ARROW)
		move_cam(data, data->movement->left);
    else if (keycode == KEY_RIGHT_ARROW)
        move_cam(data, data->movement->right);
    else if ( keycode == KEY_PLUS)
        move_cam(data, data->movement->forward);
    else if (keycode == KEY_MINUS)
        move_cam(data, data->movement->backward);
   }


