/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:01:35 by vbudilov          #+#    #+#             */
/*   Updated: 2023/08/01 14:01:37 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	parse_elements(char *file_content, t_data *data)
{
	char	**lines;
	int		length;
	int		i;

	lines = ft_split(file_content, '\n');
	length = 0;
	while (lines[length])
		length++;
	i = 0;
	while (i < length)
	{
		parse_element(lines[i], data);
		i++;
	}
	check_elements(data);
	free_array(lines);
	free(file_content);
}

void	parse_element(char *element_line, t_data *data)
{
	if (element_line[0] == '#')
		return ;
	element_line = remove_overstricked_space(element_line);
	if (element_line[0] == 'A' && element_line[1] == ' ')
		parse_ambient_light(element_line, data);
	else if (element_line[0] == 'C' && element_line[1] == ' ')
		parse_camera(element_line, data);
	else if (element_line[0] == 'L' && element_line[1] == ' ')
		parse_spot_light(element_line, data);
	else if (element_line[0] == 's' && element_line[1]
		== 'p' && element_line[2] == ' ')
		parse_sphere(element_line, data);
	else if (element_line[0] == 'p' && element_line[1]
		== 'l' && element_line[2] == ' ')
		parse_plane(element_line, data);
	else if (element_line[0] == 'c' && element_line[1]
		== 'y' && element_line[2] == ' ')
		parse_cylinder(element_line, data);
	else
		error("in element line\n", EXIT_FAILURE);
	free(element_line);
}
