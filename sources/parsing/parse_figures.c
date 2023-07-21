#include "../../includes/miniRT.h"

void parse_sphere(char *line, t_data *data) {
	t_figure *sphere_figure;
	char **elements = ft_split(line, ' ');
	if (array_lenth(elements) != 4)
		error("Wrong amount of arguments in sphere_figure\n", EXIT_FAILURE);
	sphere_figure = add_figure(data, SPHERE);
	sphere_figure->figure_body.sphere.center = parse_vector(elements[1]);
	sphere_figure->figure_body.sphere.radius = ft_atof(elements[2])/2.f;
	sphere_figure->RGB_color = parse_color(elements[3]);
	check_sphere(sphere_figure);
	data->checker.has_object++;
	free_array(elements);
}

void parse_plane(char *line, t_data *data) {
	t_figure *plane_figure;
	char **elements = ft_split(line, ' ');
	if (array_lenth(elements) != 4)
		error("Wrong amount of arguments in plane_figure\n", EXIT_FAILURE);
	plane_figure = add_figure(data, PLANE);
	plane_figure->figure_body.plane.center = parse_vector(elements[1]);
	plane_figure->figure_body.plane.normal = parse_vector(elements[2]);
	plane_figure->RGB_color = parse_color(elements[3]);
	check_plane(plane_figure);
	data->checker.has_object++;
	free_array(elements);
}

void check_plane(t_figure *figure) {
	if(is_normalized(figure->figure_body.plane.normal) == 0)
		error("Wrong plane normal\n", EXIT_FAILURE);
}

void check_sphere(t_figure *figure) {
	if (figure->figure_body.sphere.radius <= 0)
		error("Wrong sphere radius\n", EXIT_FAILURE);
}