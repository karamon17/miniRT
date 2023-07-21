#include "../includes/miniRT.h"

int is_camera_rotation_key(int keycode) {
	return (keycode == KEY_0 || keycode == KEY_1 || keycode == KEY_2 || keycode == KEY_3 ||
			keycode == KEY_4 || keycode == KEY_5 || keycode == KEY_6 || keycode == KEY_7 || keycode == KEY_8
			|| keycode == KEY_9);
}
int is_camera_movement_key(int keycode) {
	return (keycode == KEY_UP_ARROW || keycode == KEY_DOWN_ARROW || keycode == KEY_LEFT_ARROW || keycode == KEY_RIGHT_ARROW);
}

int is_object_key(int keycode) {
	return (keycode == KEY_S || keycode == KEY_D || keycode == KEY_W || keycode == KEY_Q || keycode == KEY_E || keycode == KEY_A);
}
