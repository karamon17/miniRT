#include "../includes/miniRT.h"

int main(int argc, char **argv)
{
    t_data *data;

    if (argc < 2 || argc > 3)
		wrong_argc(argv[0]);
	data = init_data(argv[1]);
	parse_rt_file(data);
	init_camera(data);
    ray_trace(data->mlx_data, data);
    mlx_hooks_handler(data);
	return (0);
}
