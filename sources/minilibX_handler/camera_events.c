#include "../../includes/miniRT.h"

void press_camera_rotation_keys(int keycode, t_data *data) {
	(void)data;
	if (keycode == KEY_0)
		printf("camera 0\n");
	else if (keycode == KEY_1)
		printf("camera 1\n");
	else if (keycode == KEY_2)
		printf("camera 2\n");
	else if (keycode == KEY_3)
		printf("camera 3\n");
	else if (keycode == KEY_4)
		printf("camera 4\n");
	else if (keycode == KEY_5)
		printf("camera 5\n");
	else if (keycode == KEY_6)
		printf("camera 6\n");
	else if (keycode == KEY_7)
		printf("camera 7\n");
	else if (keycode == KEY_8)
		printf("camera 8\n");
	else if (keycode == KEY_9)
		printf("camera 9\n");
}

void press_camera_movement_keys(int keycode, t_data *data) {
	(void)data;
	if (keycode == KEY_UP_ARROW)
		printf("camera up\n");
	else if (keycode == KEY_DOWN_ARROW)
		printf("camera down\n");
	else if (keycode == KEY_LEFT_ARROW)
		printf("camera left\n");
	else if (keycode == KEY_RIGHT_ARROW)
		printf("camera right\n");

}