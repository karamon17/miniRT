#include "../includes/miniRT.h"

int	press_keys(int keycode, void *data)
{
	if(is_object_key(keycode))
		press_object_movement_keys(keycode, data);
	else if(is_camera_movement_key(keycode))
		press_camera_movement_keys(keycode, data);
	else if(is_camera_rotation_key(keycode))
		press_camera_rotation_keys(keycode, data);
	else if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

void	mlx_hooks_handler(t_data *data)
{
	mlx_hook(data->win, 4, 1, mouse_whilling, data);
	mlx_hook(data->win, 2, 1, press_keys, (void *) 0);
	mlx_hook(data->win, 17, 1L << 2, ft_exit, (void *)0);
	mlx_loop(data->mlx);
}
