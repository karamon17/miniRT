#include "../includes/miniRT.h"

int	mouse_whilling(int button, int x, int y, t_data *data)
{
	(void ) data;
	if (button == 5)
		printf("zoom in\n");
	else if (button == 4)
		printf("zoom out\n");
	printf("position: %d %d\n", x, y);
	return (1);
}

int	press_object_movement_keys(int keycode, t_data *data)
{
	(void)data;
	if (keycode == 0) // 'A' key
	{
		printf("move left\n");
	}
	else if (keycode == 13) // 'W' key
	{
		printf("move up\n");
	}
	else if (keycode == 1) // 'S' key
	{
		printf("move down\n");
	}
	else if (keycode == 2) // 'D' key
	{
		printf("move right\n");
	}
	else if (keycode == 12) // 'Q' key
	{
		printf("rotate left\n");
	}
	else if (keycode == 14) // 'E' key
	{
		printf("rotate right\n");
	}
	return (0);
}

int	press_exit(int keycode, void *f)
{
	(void)f;
	if (keycode == 53)
		exit(0);
	return (0);
}

int	ft_exit(int keycode, void *f)
{
	(void)f;
	(void)keycode;
	exit(0);
}

void	mlx_hooks_handler(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, press_object_movement_keys, data);
	mlx_hook(data->win, 4, 1, mouse_whilling, data);
	mlx_hook(data->win, 2, 1, press_exit, (void *)0);
	mlx_hook(data->win, 17, 1L << 2, ft_exit, (void *)0);
	mlx_loop(data->mlx);
}
