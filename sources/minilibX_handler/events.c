#include "../includes/miniRT.h"

void	mlx_hooks_handler(t_data *data)
{
	mlx_hook(data->mlx_data->win, 4, 1, mouse_handle, data);
	mlx_hook(data->mlx_data->win, 2, 1, press_keys, data);
	mlx_hook(data->mlx_data->win, 17, 1L << 2, ft_exit, (void *)0);
	mlx_loop(data->mlx_data->mlx);
}
