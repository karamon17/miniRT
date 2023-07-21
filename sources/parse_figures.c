#include "../includes/miniRT.h"

void parse_sphere(char *line, t_data *data) {
	t_figure *sphere_figure;
	char **elements = ft_split(line, ' ');
	if (array_lenth(elements) != 4)
		error("Wrong amount of arguments in sphere_figure\n", EXIT_FAILURE);
	sphere_figure = malloc(sizeof(t_figure));
	add_figure(data, sphere_figure, SPHERE);
	sphere_figure->figure_body.sphere.center = parse_vector(elements[1]);
	sphere_figure->figure_body.sphere.radius = ft_atof(elements[2])/2.f;
	sphere_figure->figure_body.sphere.RGB_color = parse_color(elements[3]);
	free_array(elements);

}