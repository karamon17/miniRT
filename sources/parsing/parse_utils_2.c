/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:01:27 by vbudilov          #+#    #+#             */
/*   Updated: 2023/08/01 14:01:28 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	free_array(char **array)
{
	int	i;

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
	int	has_dot;

	has_dot = 0;
	if (!*string)
		return (0);
	if ((*string == '-' && *(string + 1) == '\0') || *string == '.')
		return (0);
	if (*string == '-')
		string++;
	while (*string)
	{
		if (!ft_isdigit(*string) && *string != '.')
			return (0);
		if (*string == '.')
			has_dot++;
		if (has_dot > 1)
			return (0);
		string++;
	}
	return (1);
}

int	is_normalized(t_vector *vector)
{
	float	length;

	length = sqrtf(vector->x * vector->x + vector->y
			* vector->y + vector->z * vector->z);
	if (length == 1)
		return (1);
	return (0);
}

void	add_to_list(t_figure *figures_list, t_figure *figure)
{
	t_figure	*current_figure;

	current_figure = figures_list;
	while (current_figure->next != NULL)
		current_figure = current_figure->next;
	current_figure->next = figure;
}

t_figure	*add_figure(t_data *data, int type)
{
	t_figure	*figure;

	figure = malloc(sizeof(t_figure));
	figure->type = type;
	figure->specular = -1.f;
	figure->next = NULL;
	if (data->figures == NULL)
		data->figures = figure;
	else
		add_to_list(data->figures, figure);
	return (figure);
}
