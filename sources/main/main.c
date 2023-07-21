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
	data->width = 800;
	data->height = 600;
	win = mlx_new_window(mlx, data->width, data->height, "miniRT");
	ray_trace(mlx, win, data);
	mlx_loop(mlx);
	return (0);
}

