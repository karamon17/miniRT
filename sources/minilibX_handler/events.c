#include "../includes/miniRT.h"

int	press_keys(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		exit(0);
	switch_object_light(keycode, data);
	if (is_object_movement_key(keycode) || is_object_rotation_key(keycode))
		work_with_object(keycode, data);
	else if (is_camera_movement_key(keycode) || is_camera_rotation_key(keycode))
		work_with_camera(keycode, data);
	mlx_destroy_image(data->mlx_data->mlx, data->mlx_data->img);
	ray_trace(data->mlx_data, data);
	return (0);
}

void	mlx_hooks_handler(t_data *data)
{
	mlx_hook(data->mlx_data->win, 4, 1, mouse_handle, data);
	mlx_hook(data->mlx_data->win, 2, 1, press_keys, data);
	mlx_hook(data->mlx_data->win, 17, 1L << 2, ft_exit, (void *) 0);
	mlx_loop(data->mlx_data->mlx);
}
