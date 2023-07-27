#include "../includes/miniRT.h"

int main(int argc, char **argv)
{
	void *mlx;
	void *win;
	mlx = mlx_init();
    t_data *data;

    if (argc < 2 || argc > 3)
		wrong_argc(argv[0]);
	data = init_data(argv[1]);
	parse_rt_file(data);
    data->mlx_data->mlx = mlx;
	win = mlx_new_window(mlx, (int)data->mlx_data->width, (int)data->mlx_data->height, "miniRT");
    data->mlx_data->win = win;
    ray_trace(mlx, data);
    mlx_hooks_handler(data);
	return (0);
}

