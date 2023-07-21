#include "../../includes/miniRT.h"


t_color *parse_color(char *string) {
	t_color *color;
	char **splited_string;
	int i;

	i = 0;
	splited_string = ft_split(string, ',');
	if(array_lenth(splited_string) != 3)
		error("Error in color declaration\n", EXIT_FAILURE);
	color = malloc(sizeof(t_color));
	if(!ft_strisdigit(splited_string[0]) || !ft_strisdigit(splited_string[1]) || !ft_strisdigit(splited_string[2]))
		error("color is not a number\n", EXIT_FAILURE);
	color->transparency = 0;
	color->red = ft_atof(splited_string[0]);
	color->green = ft_atof(splited_string[1]);
	color->blue = ft_atof(splited_string[2]);
	check_color(color);
	while (splited_string[i])
	{
		free(splited_string[i]);
		i++;
	}
	free(splited_string);
	return (color);
}

void check_color(t_color *color) {
	if(color->red < 0 || color->red > 255)
		error("red color out of range\n", EXIT_FAILURE);
	if(color->green < 0 || color->green > 255)
		error("green color out of range\n", EXIT_FAILURE);
	if(color->blue < 0 || color->blue > 255)
		error("blue color out of range\n", EXIT_FAILURE);
}

float parse_intesity(char *string) {
	float intensity;
	if(!ft_strisdigit(string))
		error("intesity is not a number\n", EXIT_FAILURE);
	intensity = ft_atof(string);
	if(intensity < 0 || intensity > 1)
		error("intesity out of range\n", EXIT_FAILURE);
	return (intensity);
}

t_vector *parse_vector(char *string) {
	char **elements = ft_split(string, ',');
	if (array_lenth(elements) != 3)
		error("Wrong arguments in vector\n", EXIT_FAILURE);
	if(!ft_strisdigit(elements[0]) || !ft_strisdigit(elements[1]) || !ft_strisdigit(elements[2]))
		error("Wrong arguments in vector\n", EXIT_FAILURE);
	t_vector *vector = malloc(sizeof(t_vector));
	vector->x = ft_atof(elements[0]);
	vector->y = ft_atof(elements[1]);
	vector->z = ft_atof(elements[2]);
	free_array(elements);
	return (vector);
}