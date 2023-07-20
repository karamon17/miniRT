#include "../includes/miniRT.h"

float ft_atof(char *string)
{
	float result;
	float decimal;
	int i;

	result = 0;
	decimal = 0;
	i = 0;
	while (string[i] >= '0' && string[i] <= '9')
	{
		result = result * 10 + (string[i] - '0');
		i++;
	}
	if (string[i] == '.')
		i++;
	while (string[i] >= '0' && string[i] <= '9')
	{
		decimal = decimal * 10 + (string[i] - '0');
		i++;
	}
	decimal = decimal / pow(10, i);
	result = result + decimal;
	return (result);
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
	splited_line = ft_split(line, ' ');
	length = array_lenth(splited_line);
	while( i < length)
	{
		if(splited_line[i][0] == '\0')
			continue ;
		new_line = ft_strjoin(new_line, splited_line[i]);
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