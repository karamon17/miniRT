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

int	string_is_float(char *string)
{
	int	i;
	int	dot;

	i = 0;
	dot = 0;
	if (string[i] == '-')
		i++;
	while (string[i])
	{
		if (string[i] == '.')
			dot++;
		if (dot > 1)
			return (0);
		if ((string[i] < '0' || string[i] > '9') && string[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

float	ft_atof(char *string)
{
	double	result;
	double	sign;
	double	power;
	int		i;

	if (string_is_float(string) == 0)
		error("Wrong float format\n", EXIT_FAILURE);
	if (is_outrange_of_float(string))
		error("float out of range\n", EXIT_FAILURE);
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
	return (sign * result / power);
}

void	do_atof(char *string, int *i, double *result, double *power)
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

int	is_outrange_of_float(char *number)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (number[i] == '-')
		i++;
	while (number[i])
		i++;
	if (i > 10)
		return (1);
	if (number[i] == '.')
		i++;
	j = i;
	while (number[i])
	{
		i++;
		j++;
	}
	if (j > 10)
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
