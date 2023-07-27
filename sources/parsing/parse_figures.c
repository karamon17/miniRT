#include "../../includes/miniRT.h"

void parse_sphere(char *line, t_data *data) {
	t_figure *sphere_figure;
	char **elements = ft_split(line, ' ');
	if (array_lenth(elements) != 4)
		error("Wrong amount of arguments in sphere_figure\n", EXIT_FAILURE);
	sphere_figure = add_figure(data, SPHERE);
	sphere_figure->center = parse_vector(elements[1]);
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
	plane_figure->center = parse_vector(elements[1]);
	plane_figure->figure_body.plane.normal = parse_vector(elements[2]);
	plane_figure->RGB_color = parse_color(elements[3]);
	check_plane(plane_figure);
	data->checker.has_object++;
	free_array(elements);
}

void parse_cylinder(char *line, t_data *data) {
	t_figure *cylinder_figure;
	char **elements = ft_split(line, ' ');
	if (array_lenth(elements) != 6)
		error("Wrong amount of arguments in cylinder_figure\n", EXIT_FAILURE);
	cylinder_figure = add_figure(data, CYLINDER);
	cylinder_figure->center = parse_vector(elements[1]);
	cylinder_figure->figure_body.cylinder.normal = parse_vector(elements[2]);
	cylinder_figure->figure_body.cylinder.radius = ft_atof(elements[3])/2.f;
	cylinder_figure->figure_body.cylinder.height = ft_atof(elements[4]);
	cylinder_figure->RGB_color = parse_color(elements[5]);
	check_cylinder(cylinder_figure);
	data->checker.has_object++;
	free_array(elements);
}

void check_plane(t_figure *figure) {
	(void)figure;
	// if(is_normalized(figure->figure_body.plane.normal) == 0)
	// 	error("Wrong plane normal\n", EXIT_FAILURE);
}

void check_sphere(t_figure *figure) {
	if (figure->figure_body.sphere.radius <= 0)
		error("Wrong sphere radius\n", EXIT_FAILURE);
}

void check_cylinder(t_figure *figure) {
	(void)figure;
	// if (figure->figure_body.cylinder.radius <= 0)
	// 	error("Wrong cylinder radius\n", EXIT_FAILURE);
	// if (figure->figure_body.cylinder.height <= 0)
	// 	error("Wrong cylinder height\n", EXIT_FAILURE);
}