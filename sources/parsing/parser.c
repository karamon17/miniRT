#include "../../includes/miniRT.h"

void check_elements(t_data *data);

void parse_elements(char *file_content, t_data *data) {

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
	check_elements(data);
}

void check_elements(t_data *data) {
	if (data->checker.camera_init == 0)
		error("No camera in scene\n", EXIT_FAILURE);
	if (data->checker.has_ambient == 0)
		error("No ambient light in scene\n", EXIT_FAILURE);
	if (data->checker.has_light == 0)
		error("No light in scene\n", EXIT_FAILURE);
	if (data->checker.has_object == 0)
		error("No object in scene\n", EXIT_FAILURE);
}

void parse_element(char *element_line, t_data *data) {
	if (element_line[0] == '#')
		return;
	element_line = remove_overstricked_space(element_line);
	if (element_line[0] == 'A' && element_line[1] == ' ')
		parse_ambient_light(element_line, data);
	else if (element_line[0] == 'C' && element_line[1] == ' ')
		parse_camera(element_line, data);
	else if (element_line[0] == 'L' && element_line[1] == ' ')
		parse_spot_light(element_line, data);
	else if (element_line[0] == 's' && element_line[1] == 'p' && element_line[2] == ' ')
		parse_sphere(element_line, data);
/*	else if (element_line[0] == 'p' && element_line[1] == 'l' && element_line[2] == ' ')
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



















