/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_figures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <gkhaishb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:00:49 by vbudilov          #+#    #+#             */
/*   Updated: 2023/08/03 13:16:51 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	parse_sphere(char *line, t_data *data)
{
	t_figure	*sphere_figure;
	char		**elements;

	elements = ft_split(line, ' ');
	if (array_lenth(elements) != 4)
		error("Wrong amount of arguments in sphere_figure\n", EXIT_FAILURE);
	sphere_figure = add_figure(data, SPHERE, 100);
	sphere_figure->center = parse_vector(elements[1]);
	sphere_figure->body.sphere.rad = ft_atof(elements[2]) / 2.f;
	sphere_figure->rgb_color = parse_color(elements[3]);
	check_sphere(sphere_figure);
	data->checker.has_object++;
	free_array(elements);
}

void	parse_plane(char *line, t_data *data)
{
	t_figure	*plane_figure;
	char		**elements;

	elements = ft_split(line, ' ');
	if (array_lenth(elements) != 4)
		error("Wrong amount of arguments in plane_figure\n", EXIT_FAILURE);
	plane_figure = add_figure(data, PLANE, 500);
	plane_figure->center = parse_vector(elements[1]);
	plane_figure->body.plane.normal = parse_vector(elements[2]);
	plane_figure->rgb_color = parse_color(elements[3]);
	check_plane(plane_figure);
	data->checker.has_object++;
	free_array(elements);
}

void	parse_cylinder(char *line, t_data *data)
{
	t_figure	*cylinder_figure;
	char		**elements;

	elements = ft_split(line, ' ');
	if (array_lenth(elements) != 6)
		error("Wrong amount of arguments in cylinder_figure\n", EXIT_FAILURE);
	cylinder_figure = add_figure(data, CYLINDER, 100);
	cylinder_figure->center = parse_vector(elements[1]);
	cylinder_figure->body.cyl.normal = parse_vector(elements[2]);
	cylinder_figure->body.cyl.rad = ft_atof(elements[3]) / 2.f;
	cylinder_figure->body.cyl.height = ft_atof(elements[4]);
	cylinder_figure->rgb_color = parse_color(elements[5]);
	check_cylinder(cylinder_figure);
	data->checker.has_object++;
	free_array(elements);
}

void	check_plane(t_figure *figure)
{
	if (is_normalized(&figure->body.plane.normal) == 0)
		error("Wrong plane normal\n", EXIT_FAILURE);
}

void	check_sphere(t_figure *figure)
{
	if (figure->body.sphere.rad <= 0)
		error("Wrong sphere radius\n", EXIT_FAILURE);
}
