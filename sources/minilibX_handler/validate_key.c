#include "../includes/miniRT.h"

int is_camera_rotation_key(int keycode) {
	return (keycode == KEY_1 || keycode == KEY_2 || keycode == KEY_3 ||
			keycode == KEY_4 || keycode == KEY_5 || keycode == KEY_6);
}
int is_camera_movement_key(int keycode) {
	return (keycode == KEY_UP_ARROW || keycode == KEY_DOWN_ARROW
    || keycode == KEY_LEFT_ARROW || keycode == KEY_RIGHT_ARROW
    || keycode == KEY_PLUS || keycode == KEY_MINUS);
}

int is_object_movement_key(int keycode) {
	return (keycode == KEY_S || keycode == KEY_D || keycode == KEY_W
    || keycode == KEY_Q || keycode == KEY_E || keycode == KEY_A);
}

int is_object_rotation_key(int keycode) {
	return (keycode == KEY_Z || keycode == KEY_C || keycode == KEY_R || keycode == KEY_F);
}

int is_chosen_object(int keycode, t_data *data) {
	return (data->closest_figure != NULL &&
			(is_object_movement_key(keycode) || is_object_rotation_key(keycode)));
}

void switch_object_light(int keycode, t_data *data) {
	if(keycode == KEY_SPACE)
		data->checker.object_light_toggle = !data->checker.object_light_toggle;
}