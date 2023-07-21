#include "../../includes/miniRT.h"

int	press_object_movement_keys(int keycode, t_data *data)
{
	(void)data;
	if (keycode == KEY_S)
		printf("object down\n");
	else if (keycode == KEY_D)
		printf("object right\n");
	else if (keycode == KEY_W)
		printf("object up\n");
	else if (keycode == KEY_Q)
		printf("object left\n");
	else if (keycode == KEY_E)
		printf("object forward\n");
	else if (keycode == KEY_A)
		printf("object backward\n");
	return (0);
}