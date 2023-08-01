/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:01:06 by vbudilov          #+#    #+#             */
/*   Updated: 2023/08/01 14:01:08 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	parse_ambient_light(char *line, t_data *data)
{
	t_light	*light;
	char	**split_line;

	if (data->checker.has_ambient >= 1)
		error("Ambient lightning (A) can only be declared once in the scene\n",
			EXIT_FAILURE);
	data->checker.has_ambient++;
	split_line = ft_split(line, ' ');
	if (array_lenth(split_line) != 3)
		error("Wrong amount of arguments in ambient\n", EXIT_FAILURE);
	light = new_ambient_light(data);
	light->intensity = parse_intesity(split_line[1]);
	light->rgb_color = parse_color(split_line[2]);
	free_array(split_line);
}

void	parse_spot_light(char *line, t_data *data)
{
	t_light	*light;
	char	**elements;

	if (data->checker.has_spot >= 1)
		error("Spot light (l) can only be declared once in the scene\n",
			EXIT_FAILURE);
	elements = ft_split(line, ' ');
	if (array_lenth(elements) != 4)
		error("Wrong amount of arguments in spot light\n", EXIT_FAILURE);
	light = new_spot_light(data);
	light->vector = parse_vector(elements[1]);
	light->intensity = parse_intesity(elements[2]);
	light->rgb_color = parse_color(elements[3]);
	free_array(elements);
}
