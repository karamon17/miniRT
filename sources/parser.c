#include "../includes/miniRT.h"

void parse_elements(char *file_content, t_data *data);

void error(const char *string, int i);

void parse_element(char *element_line, t_data *data);

char *remove_overstricked_space(char *line);

void parse_ambient_light(char *line, t_data *data);

int array_lenth(char **array);

char		*read_file(char *str, int fd)
{
    char	buf[BUFFER_SIZE + 1];
    int		retairment;

    while ((retairment = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        buf[retairment] = '\0';
        if (!(str = ft_strjoin(str, buf)))
			error("Error in ft_strjoin\n", EXIT_FAILURE);
	}
    return (str);
}

void parse_rt_file(t_data *data) {
    int fd;
    char *file_content;

    if ((fd = open(data->filename, 0)) == -1)
		error("Error opening file\n", EXIT_FAILURE);
    file_content = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    file_content = read_file(file_content, fd);
    parse_elements(file_content, data);
}

void parse_elements(char *file_content, t_data *data) {

	data->result_init = 0;
	data->all_init = 0;
	data->camera_init = 0;
	data->has_light = 0;
	data->has_ambient = 0;

	char **lines = ft_split(file_content, '\n');
	int array_lenth = 0;
	while (lines[array_lenth])
		array_lenth++;
	int i = 0;
	while (i < array_lenth)
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
/*	else if (element_line[0] == 'C' && element_line[1] == ' ')
		parse_camera(element_line, data);
	else if (element_line[0] == 'L' && element_line[1] == ' ')
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
		error("Error in element line\n", EXIT_FAILURE);

}

void parse_ambient_light(char *line, t_data *data)
{
	if(data->has_ambient >= 1)
		error("Ambient lightning (A) can only be declared once in the scene\n", EXIT_FAILURE);
	data->has_ambient++;
	char **splited_line = ft_split(line, ' ');
	if(array_lenth(splited_line) != 3)
		error("Error in ambient lightning (A) declaration\n", EXIT_FAILURE);
	data->scene-> = malloc(sizeof());

}

int array_lenth(char **array) {
	int i = 0;
	while (array[i])
		i++;
	return (i);
}

char *remove_overstricked_space(char *line) {
	char **splited_line;
	char *new_line;

	splited_line = ft_split(line, ' ');
	new_line = ft_strjoin(splited_line[0], " ");

	return (new_line);
}


void error(const char *string, int i) {
	write(2, "Error\n", 6);
	write(2, string, ft_strlen(string));
	exit(i);
}
