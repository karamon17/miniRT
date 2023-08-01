/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objet_interceptions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <gkhaishb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:16:27 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/08/01 17:07:16 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_figure	*check_intersection(t_figure *figure, t_vector vector, t_vector ray)
{
	while (figure)
	{
		if (figure->type == SPHERE && sphere_intercept(figure, vector, ray))
			return (figure);
		if (figure->type == PLANE && plane_intercept(figure, vector, ray) && \
		plane_intercept(figure, vector, ray) != INFINITY)
			return (figure);
		if (figure->type == CYLINDER && cylinder_intersect(vector, ray, figure) \
		&& cylinder_intersect(vector, ray, figure) != INFINITY)
			return (figure);
		figure = figure->next;
	}
	return (0);
}

float	plane_intercept(t_figure *plane, t_vector vector, t_vector ray)
{
	float		a;
	t_vector	temp;

	a = dot2(plane->body.plane.normal, ray);
	if (a == 0)
		return (INFINITY);
	temp = vector_subtract2(plane->center, vector);
	a = dot2(temp, plane->body.plane.normal) / a;
	if (a < EPSILON)
		return (INFINITY);
	return (a);
}

float	sphere_intercept(t_figure *sphere, t_vector vector, t_vector ray)
{
	t_abc		abc;
	float		discr;
	float		dist_1;
	t_vector	oc;

	oc = vector_subtract2(vector, sphere->center);
	abc.a = dot2(ray, ray);
	abc.b = 2 * dot2(oc, ray);
	abc.c = dot2(oc, oc) - (sphere->body.sphere.rad * sphere->body.sphere.rad);
	discr = abc.b * abc.b - (4 * abc.a * abc.c);
	if (discr < 0)
		return (0);
	dist_1 = (-abc.b - sqrt(discr)) / 2 / abc.a;
	if (dist_1 > 0)
		return (dist_1);
	return (0);
}

t_figure	*closest_inters(t_figure *figure, t_vector vector, t_vector ray, \
float *closest_dist)
{
	t_figure	*closest_figure;
	float		dist;

	closest_figure = NULL;
	*closest_dist = 0;
	while (figure)
	{
		if (figure->type == SPHERE)
			dist = sphere_intercept(figure, vector, ray);
		else if (figure->type == PLANE)
			dist = plane_intercept(figure, vector, ray);
		else if (figure->type == CYLINDER)
			dist = cylinder_intersect(vector, ray, figure);
		if ((dist > 0) && (dist < *closest_dist || closest_figure == NULL))
		{
			*closest_dist = dist;
			closest_figure = figure;
		}
		figure = figure->next;
	}
	return (closest_figure);
}
