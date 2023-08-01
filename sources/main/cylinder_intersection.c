/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <gkhaishb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:16:20 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/08/01 16:16:21 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"


static int		solve_cylinder(float x[2], t_vector o, t_vector d, t_figure *cyl)
{
	t_vector	v1;
	t_vector	v2;
	t_abc		abc;

	v1 = vector_subtract2(d, mult_vect2(dot2(d, cyl->body.cyl.normal), cyl->body.cyl.normal));
	v2 = vector_subtract2(vector_subtract2(o, cyl->center), mult_vect2(dot2(vector_subtract2(o, cyl->center), cyl->body.cyl.normal), cyl->body.cyl.normal));
	abc.a = dot2(v1, v1);
	abc.b = 2 * dot2(v1, v2);
	abc.c = dot2(v2, v2) - cyl->body.cyl.rad * cyl->body.cyl.rad;
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

static t_vector calc_cy_normal(float x2[2], t_vector o, t_vector d, t_figure *cyl)
{
	t_abc		abc;

	abc.c = cyl->body.cyl.height;
	if ((cyl->body.cyl.dist1 >= 0 && cyl->body.cyl.dist1 <= abc.c
				&& x2[0] > EPSILON) && (cyl->body.cyl.dist2 >= 0
				&& cyl->body.cyl.dist2 <= abc.c && x2[1] > EPSILON))
	{
		abc.a = x2[0] < x2[1] ? cyl->body.cyl.dist1 : cyl->body.cyl.dist2;
		abc.b = x2[0] < x2[1] ? x2[0] : x2[1];
	}
	else if (cyl->body.cyl.dist1 >= 0 && cyl->body.cyl.dist1 <= abc.c && x2[0] > EPSILON)
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
	return (normalize2(vector_subtract2(vector_subtract2(mult_vect2(abc.b, d), mult_vect2(abc.a, cyl->body.cyl.normal)), vector_subtract2(cyl->center, o))));
}

static float	cy_intersection(t_vector o, t_vector d, t_vector *cy_normal, t_figure *cyl)
{
	float		x2[2];
	float 		height;

	height = cyl->body.cyl.height;
	if (solve_cylinder(x2, o, d, cyl) == 0)
		return (INFINITY);
	cyl->body.cyl.dist1 = dot2(cyl->body.cyl.normal, vector_subtract2(mult_vect2(x2[0], d), vector_subtract2(cyl->center, o)));
	cyl->body.cyl.dist2 = dot2(cyl->body.cyl.normal, vector_subtract2(mult_vect2(x2[1], d), vector_subtract2(cyl->center, o)));
	if (!((cyl->body.cyl.dist1 >= 0 && cyl->body.cyl.dist1 <= height
					&& x2[0] > EPSILON) || (cyl->body.cyl.dist2 >= 0
					&& cyl->body.cyl.dist2 <= height && x2[0] > EPSILON)))
		return (INFINITY);
	*cy_normal = calc_cy_normal(x2, o, d, cyl);
	return (x2[0]);
}

void	ft_newplane(t_figure *new_plane, t_figure *new_plane2, t_vector v4, t_figure *cyl)
{
	new_plane->body.plane.normal = v4;
	new_plane->center = cyl->center;
	new_plane2->body.plane.normal = v4;
	new_plane2->center = vector_add2(cyl->center, mult_vect2(cyl->body.cyl.height, cyl->body.cyl.normal));
}

static float	caps_intersection(t_vector o, t_vector d, t_figure *cyl)
{
	t_abc		id;
	t_abc		ab;
	t_figure 	new_plane;
	t_figure 	new_plane2;

	ft_newplane(&new_plane, &new_plane2, cyl->body.cyl.normal, cyl);
	id.a = plane_intercept(&new_plane, o, d);
	id.b = plane_intercept(&new_plane2, o, d);
	if (id.a < INFINITY || id.b < INFINITY)
	{
		ab.a = distance2(vector_add2(o, mult_vect2(id.a, d)), cyl->center);
		ab.b = distance2(vector_add2(o, mult_vect2(id.b, d)), vector_add2(cyl->center, mult_vect2(cyl->body.cyl.height, cyl->body.cyl.normal)));
		if ((id.a < INFINITY && ab.a <= cyl->body.cyl.rad)
				&& (id.b < INFINITY && ab.b <= cyl->body.cyl.rad))
			return (id.a < id.b ? id.a : id.b);
		else if (id.a < INFINITY	&& ab.a <= cyl->body.cyl.rad)
			return (id.a);
		else if (id.b < INFINITY && ab.b <= cyl->body.cyl.rad)
			return (id.b);
	}
	return (INFINITY);
}

float	cylinder_intersection(t_vector o, t_vector d, t_figure *cylinder)
{
	float	cylinder_inter;
	float	caps_inter;
	t_vector cy_normal;

	cylinder_inter = cy_intersection(o, d, &cy_normal, cylinder);
	caps_inter = caps_intersection(o, d, cylinder);
	if (cylinder_inter < INFINITY || caps_inter < INFINITY)
	{
		if (cylinder_inter < caps_inter)
		{
			cylinder->normal = cy_normal;
			return (cylinder_inter);
		}
		cylinder->normal = cylinder->body.cyl.normal;
		return (caps_inter);
	}
	return (INFINITY);
}
