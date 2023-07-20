#include "../includes/miniRT.h"

void parse_ambient_light(char *line, t_data *data)
{
	t_light *light;
	if(data->has_ambient >= 1)
		error("Ambient lightning (A) can only be declared once in the scene\n", EXIT_FAILURE);
	data->has_ambient++;
	char **split_line = ft_split(line, ' ');
	if(array_lenth(split_line) != 3)
		error("Error in ambient lightning (A) declaration\n", EXIT_FAILURE);
	light = new_amient_light(data);
	light->intensity = parse_intesity(split_line[1]);
	light->RGB_color = parse_color(split_line[2]);
	free_array(split_line);
}

t_light *new_amient_light(t_data *data) {
	t_light *light;

	light = malloc(sizeof(t_light));
	light->type = 'A';
	if(data->has_light == 0)
		data->lights = light;
	else
		data->lights->next = light;
	light->next = NULL;
	return (light);
}
