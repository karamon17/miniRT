
#include "../../includes/miniRT.h"


t_data *init_data(char *input);



int main(int argc, char **argv)
{
    t_data *data;

    if (argc < 2 || argc > 3)
		wrong_argc(argv[0]);
	data = init_data(argv[1]);

	parse_rt_file(data);

	print_camera_content(data->camera);
	print_light_content(data->lights);
	print_figures_content(data->figures);
	system("leaks minirt");
	return (0);
}

