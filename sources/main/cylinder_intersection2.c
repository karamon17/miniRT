/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersect2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <gkhaishb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:44:23 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/08/01 16:44:52 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

float	ft_ternar(float a, float b)
{
	if (a < b)
		return (a);
	return (b);
}

static float	caps_intersection(t_vector o, t_vector d, t_figure *cyl)
{
	t_abc		id;
	t_abc		ab;
	t_figure	new_plane;
	t_figure	new_plane2;

	ft_newplane(&new_plane, &new_plane2, cyl->body.cyl.normal, cyl);
	id.a = plane_intercept(&new_plane, o, d);
	id.b = plane_intercept(&new_plane2, o, d);
	if (id.a < INFINITY || id.b < INFINITY)
	{
		ab.a = distance(vector_add(o, mult_vect(id.a, d)), new_plane.center);
		ab.b = distance(vector_add(o, mult_vect(id.b, d)), new_plane2.center);
		if (ab.a <= cyl->body.cyl.rad && ab.b <= cyl->body.cyl.rad)
			return (ft_ternar(id.a, id.b));
		else if (ab.a <= cyl->body.cyl.rad)
			return (id.a);
		else if (ab.b <= cyl->body.cyl.rad)
			return (id.b);
	}
	return (INFINITY);
}

float	cylinder_intersect(t_vector o, t_vector d, t_figure *cylinder)
{
	float		cylinder_inter;
	float		caps_inter;
	t_vector	cy_normal;

	cylinder_inter = cy_intersection(o, d, &cy_normal, cylinder);
	caps_inter = caps_intersection(o, d, cylinder);
	if (cylinder_inter < INFINITY || caps_inter < INFINITY)
	{
		if (cylinder_inter < caps_inter && cylinder_inter > EPSILON)
		{
			cylinder->normal = cy_normal;
			return (cylinder_inter);
		}
		if (cylinder->body.cyl.normal.z > 0)
			cylinder->normal = cylinder->body.cyl.normal;
		else if (cylinder->body.cyl.normal.z <= 0)
			cylinder->normal = mult_vect(-1, cylinder->body.cyl.normal);
		return (caps_inter);
	}
	return (INFINITY);
}
