#include "../../includes/miniRT.h"

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
	free_array(splited_line);
	return (new_line);
}

