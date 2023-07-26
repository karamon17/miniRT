#include "../../includes/miniRT.h"

int	press_keys(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		exit(0);
	if(data->closest_figure == NULL)
		return (0);
	if(is_object_key(keycode))
		press_object_movement_keys(keycode, data);
	else if(is_object_rotation_key(keycode))
		press_object_rotation_keys(keycode, data);
	else if(is_camera_movement_key(keycode))
		press_camera_movement_keys(keycode, data);
	else if(is_camera_rotation_key(keycode))
		press_camera_rotation_keys(keycode, data);
	/*else if(is_light_key(keycode))
		press_light_movement_keys(keycode, data);*/
	ray_trace(data->mlx_data->mlx, data);
	return (0);
}

int	press_object_movement_keys(int keycode, t_data *data)
{
	if (keycode == KEY_S)
		move_object(data, data->movement->down);
	else if (keycode == KEY_D)
		move_object(data, data->movement->right);
	else if (keycode == KEY_W)
		move_object(data, data->movement->up);
	else if (keycode == KEY_A)
		move_object(data, data->movement->left);
	else if (keycode == KEY_E)
		move_object(data, data->movement->forward);
	else if (keycode == KEY_Q)
		move_object(data, data->movement->backward);
	return (0);
}

void press_object_rotation_keys(int keycode, t_data *data) {
	if (keycode == KEY_Z)
		rotate_object(data, data->movement->rotate_y_left);
	else if (keycode == KEY_C)
		rotate_object(data, data->movement->rotate_y_right);
	else if (keycode == KEY_R)
		rotate_object(data, data->movement->rotate_x_left);
	else if (keycode == KEY_F)
		rotate_object(data, data->movement->rotate_x_right);
}