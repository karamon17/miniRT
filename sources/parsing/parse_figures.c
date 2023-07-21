#include "../../includes/miniRT.h"

void parse_sphere(char *line, t_data *data) {
	t_figure *sphere_figure;
	char **elements = ft_split(line, ' ');
	if (array_lenth(elements) != 4)
		error("Wrong amount of arguments in sphere_figure\n", EXIT_FAILURE);
	sphere_figure = add_figure(data, SPHERE);
	sphere_figure->figure_body.sphere.center = parse_vector(elements[1]);
	sphere_figure->figure_body.sphere.radius = ft_atof(elements[2])/2.f;
	sphere_figure->figure_body.sphere.RGB_color = parse_color(elements[3]);
	check_sphere(sphere_figure);
	data->checker.has_object++;
	free_array(elements);
}

void check_sphere(t_figure *figure) {
	if (figure->figure_body.sphere.radius <= 0)
		error("Wrong sphere radius\n", EXIT_FAILURE);
}