#include "../includes/miniRT.h"

void check_color(t_color *color);

t_color *parse_color(char *string) {
	t_color *color;
	char **splited_string;
	int i;

	i = 0;
	splited_string = ft_split(string, ',');
	if(array_lenth(splited_string) != 3)
		error("Error in color declaration\n", EXIT_FAILURE);
	color = malloc(sizeof(t_color));
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
	intensity = ft_atof(string);
	if(intensity < 0 || intensity > 1)
		error("intesity out of range\n", EXIT_FAILURE);
	return (intensity);
}