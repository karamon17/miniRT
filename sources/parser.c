#include "../includes/miniRT.h"

void parse_camera(char *line, t_data *data);

t_vector *parse_vector(char *string);

void parse_elements(char *file_content, t_data *data) {

	data->result_init = 0;
	data->all_init = 0;
	data->camera_init = 0;
	data->has_light = 0;
	data->has_ambient = 0;

	char **lines = ft_split(file_content, '\n');
	int length = 0;
	while (lines[length])
		length++;
	int i = 0;
	while (i < length)
	{
		parse_element(lines[i], data);
		i++;
	}
	if (data->result_init == 0 || data->all_init == 0 || data->scene->camera == NULL)
		error("Not enough elements to render a scene\n", EXIT_FAILURE);
}

void parse_element(char *element_line, t_data *data) {
	if (element_line[0] == '#')
		return;
	element_line = remove_overstricked_space(element_line);
	if (element_line[0] == 'A' && element_line[1] == ' ')
		parse_ambient_light(element_line, data);
	else if (element_line[0] == 'C' && element_line[1] == ' ')
		parse_camera(element_line, data);
/*	else if (element_line[0] == 'L' && element_line[1] == ' ')
		parse_light(element_line, data);
	else if (element_line[0] == 's' && element_line[1] == 'p' && element_line[2] == ' ')
		parse_sphere(element_line, data);
	else if (element_line[0] == 'p' && element_line[1] == 'l' && element_line[2] == ' ')
		parse_plane(element_line, data);
	else if (element_line[0] == 's' && element_line[1] == 'q' && element_line[2] == ' ')
		parse_square(element_line, data);
	else if (element_line[0] == 'c' && element_line[1] == 'y' && element_line[2] == ' ')
		parse_cylinder(element_line, data);
	else if (element_line[0] == 't' && element_line[1] == 'r' && element_line[2] == ' ')
		parse_triangle(element_line, data);*/
	else
		error("in element line\n", EXIT_FAILURE);

}

void parse_camera(char *line, t_data *data) {
	char **elements = ft_split(line, ' ');
	if (elements[4] != NULL)
		error("in camera line\n", EXIT_FAILURE);
	t_camera *camera = malloc(sizeof(t_camera));
	camera->origin = parse_vector(elements[1]);
	camera->direction = parse_vector(elements[2]);
	camera->fov = ft_atoi(elements[3]);
	if (camera->fov < 0 || camera->fov > 180)
		error("in camera line\n", EXIT_FAILURE);
	camera->next = NULL;
	if (data->scene->camera == NULL)
		data->scene->camera = camera;
	else
	{
		t_camera *tmp = data->scene->camera;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = camera;
	}
	data->camera_init = 1;

}

t_vector *parse_vector(char *string) {
	char **elements = ft_split(string, ',');
	if (array_lenth(elements) != 3)
		error("in vector line\n", EXIT_FAILURE);
	t_vector *vector = malloc(sizeof(t_vector));
	vector->x = ft_atof(elements[0]);
	vector->y = ft_atof(elements[1]);
	vector->z = ft_atof(elements[2]);
	free_array(elements);
	return (vector);
}



