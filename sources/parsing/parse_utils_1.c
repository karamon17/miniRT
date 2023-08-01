/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:01:20 by vbudilov          #+#    #+#             */
/*   Updated: 2023/08/01 14:01:21 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

float	ft_atof(char *string)
{
	float	result;
	float	sign;
	float	power;
	int		i;

	i = 0;
	result = 0;
	sign = 1;
	power = 1;
	if (string[i] == '-')
	{
		sign = -1;
		i++;
	}
	do_atof(string, &i, &result, &power);
	if (is_outrange_of_float(sign * result / power))
		error("float out of range\n", EXIT_FAILURE);
	return (sign * result / power);
}

void	do_atof(char *string, int *i, float *result, float *power)
{
	while (string[*i] >= '0' && string[*i] <= '9')
	{
		*result = *result * 10 + (string[*i] - '0');
		*i += 1;
	}
	if (string[*i] == '.')
		*i += 1;
	while (string[*i] >= '0' && string[*i] <= '9')
	{
		*result = *result * 10 + (string[*i] - '0');
		*power *= 10;
		*i += 1;
	}
}

int	is_outrange_of_float(float number)
{
	if (number > 2147483647.f || number < -2147483648.f)
		return (1);
	return (0);
}

int	array_lenth(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

char	*remove_overstricked_space(char *line)
{
	char	**splited_line;
	char	*new_line;
	int		i;
	int		length;

	i = 0;
	new_line = malloc(sizeof(char) * 1);
	new_line[0] = '\0';
	splited_line = ft_split(line, ' ');
	length = array_lenth(splited_line);
	while (i < length)
	{
		new_line = ft_strjoin(new_line, splited_line[i]);
		if (i != length - 1)
			new_line = ft_strjoin(new_line, " ");
		i++;
	}
	free_array(splited_line);
	return (new_line);
}
