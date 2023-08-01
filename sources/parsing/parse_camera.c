#include "../../includes/miniRT.h"

void parse_camera(char *line, t_data *data) {
	char **elements = ft_split(line, ' ');
	if (elements[4] != NULL)
		error("Wrong amount of arguments in camera\n", EXIT_FAILURE);
	t_camera *camera = new_camera(data);
	camera->origin = parse_vector(elements[1]);
	camera->direction = parse_vector(elements[2]);
	camera->fov = (float)ft_atoi(elements[3]);
	check_camera(camera);
	data->camera = camera;
	free_array(elements);
}

void check_camera(t_camera *camera) {
	if (camera->fov < 0 || camera->fov > 180)
		error("Wrong FOV\n", EXIT_FAILURE);
	if (is_normalized(&camera->direction) == 0)
		error("Wrong camera direction. Has to be normalized\n", EXIT_FAILURE);
}
