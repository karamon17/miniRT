/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersect.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <gkhaishb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:16:20 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/08/01 16:48:19 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static int	solve_cylinder(float x[2], t_vector o, t_vector d, t_figure *cyl)
{
	t_vector	v1;
	t_vector	v2;
	t_abc		abc;

	v1 = vector_subtract(d, mult_vect(dot(d, cyl->body.cyl.normal), \
	cyl->body.cyl.normal));
	v2 = vector_subtract(vector_subtract(o, cyl->center), \
	mult_vect(dot(vector_subtract(o, cyl->center), cyl->body.cyl.normal), \
	cyl->body.cyl.normal));
	abc.a = dot(v1, v1);
	abc.b = 2 * dot(v1, v2);
	abc.c = dot(v2, v2) - cyl->body.cyl.rad * cyl->body.cyl.rad;
	x[0] = (-abc.b + sqrt(abc.b * abc.b - 4 * abc.a * abc.c)) / (2 * abc.a);
	x[1] = (-abc.b - sqrt(abc.b * abc.b - 4 * abc.a * abc.c)) / (2 * abc.a);
	if ((x[0] != x[0] && x[1] != x[1]) || (x[0] < EPSILON && x[1] < EPSILON))
	{
		x[0] = INFINITY;
		x[1] = INFINITY;
		return (0);
	}
	return (1);
}

void	help_calc_cy(float x2[2], t_abc	*abc, t_figure *cyl)
{
	if (x2[0] < x2[1])
		abc->a = cyl->body.cyl.dist1;
	else
		abc->a = cyl->body.cyl.dist2;
	if (x2[0] < x2[1])
		abc->b = x2[0];
	else
		abc->b = x2[1];
}

static t_vector	calc_cy_normal(float x2[2], t_vector o, t_vector d, \
t_figure *cyl)
{
	t_abc		abc;

	abc.c = cyl->body.cyl.height;
	if ((cyl->body.cyl.dist1 >= 0 && cyl->body.cyl.dist1 <= abc.c \
		&& x2[0] > EPSILON) && (cyl->body.cyl.dist2 >= 0 \
		&& cyl->body.cyl.dist2 <= abc.c && x2[1] > EPSILON))
		help_calc_cy(x2, &abc, cyl);
	else if (cyl->body.cyl.dist1 >= 0 && cyl->body.cyl.dist1 <= \
	abc.c && x2[0] > EPSILON)
	{
		abc.a = cyl->body.cyl.dist1;
		abc.b = x2[0];
	}
	else
	{
		abc.a = cyl->body.cyl.dist2;
		abc.b = x2[1];
	}
	x2[0] = abc.b;
	return (normalize(vector_subtract(vector_subtract(mult_vect(abc.b, d), \
	mult_vect(abc.a, cyl->body.cyl.normal)), \
	vector_subtract(cyl->center, o))));
}

float	cy_intersection(t_vector o, t_vector d, \
t_vector *cy_normal, t_figure *cyl)
{
	float	x2[2];
	float	height;

	height = cyl->body.cyl.height;
	if (solve_cylinder(x2, o, d, cyl) == 0)
		return (INFINITY);
	cyl->body.cyl.dist1 = dot(cyl->body.cyl.normal, \
	vector_subtract(mult_vect(x2[0], d), vector_subtract(cyl->center, o)));
	cyl->body.cyl.dist2 = dot(cyl->body.cyl.normal, \
	vector_subtract(mult_vect(x2[1], d), vector_subtract(cyl->center, o)));
	if (!((cyl->body.cyl.dist1 >= 0 && cyl->body.cyl.dist1 <= height \
		&& x2[0] > EPSILON) || (cyl->body.cyl.dist2 >= 0 \
		&& cyl->body.cyl.dist2 <= height && x2[0] > EPSILON)))
		return (INFINITY);
	*cy_normal = calc_cy_normal(x2, o, d, cyl);
	return (x2[0]);
}

void	ft_newplane(t_figure *new_plane, t_figure *new_plane2, \
t_vector cyl_normal, t_figure *cyl)
{
	new_plane->body.plane.normal = cyl_normal;
	new_plane->center = cyl->center;
	new_plane2->body.plane.normal = cyl_normal;
	new_plane2->center = vector_add(cyl->center, \
	mult_vect(cyl->body.cyl.height, cyl_normal));
}
