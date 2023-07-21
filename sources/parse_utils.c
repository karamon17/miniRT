#include <stdbool.h>
#include "../includes/miniRT.h"

int is_outrange_of_float(double number);

float ft_atof(char *string)
{
	double result;
	double sign;
	double power;
	int i;

	i = 0;
	result = 0;
	sign = 1;
	power = 1;
	if (string[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (string[i] >= '0' && string[i] <= '9')
	{
		result = result * 10 + (string[i] - '0');
		i++;
	}
	if (string[i] == '.')
		i++;
	while (string[i] >= '0' && string[i] <= '9')
	{
		result = result * 10 + (string[i] - '0');
		power *= 10;
		i++;
	}
	if(is_outrange_of_float(sign * result / power))
		error("float out of range\n", EXIT_FAILURE);
	return (sign * result / power);
}

int is_outrange_of_float(double number) {
	if (number > 2147483647 || number < -2147483648)
		return (1);
	return (0);
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
	int i;
	int length;

	i = 0;
	new_line = malloc(sizeof(char) * 1);
	new_line[0] = '\0';
	splited_line = ft_split(line, ' ');
	length = array_lenth(splited_line);
	while( i < length)
	{
		new_line = ft_strjoin(new_line, splited_line[i]);
		if(i != length - 1)
			new_line = ft_strjoin(new_line, " ");
		i++;
	}
	return (new_line);
}

void free_array(char **array) {
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	ft_strisdigit(char *string)
{
	int has_dot;

	has_dot = 0;
	if (!*string)
		return (0);
	if ((*string == '-' && *(string + 1) == '\0') || *string == '.')
		return (0);
	if (*string == '-')
		string++;
	while (*string)
	{
		if (!ft_isdigit(*string) && *string !='.')
			return (0);
		if(*string == '.')
			has_dot++;
		if(has_dot > 1)
			return (0);
		string++;
	}
	return (1);
}

int is_normalized(t_vector *vector) {
	float length = sqrt(vector->x * vector->x + vector->y * vector->y + vector->z * vector->z);
	if (length == 1)
		return (1);
	return (0);
}

void add_to_list(t_figure *figures_list, t_figure *figure) {
	t_figure *current_figure = figures_list;
	while (current_figure->next != NULL)
		current_figure = current_figure->next;
	current_figure->next = figure;
}

void add_figure(t_data *data, t_figure *figure, int type) {

	figure->type = type;
	figure->next = NULL;
	if(data->figures == NULL)
		data->figures = figure;
	else
		add_to_list(data->figures, figure);
}