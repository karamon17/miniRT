/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <gkhaishb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:05:19 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/08/01 17:15:42 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_vector	normalize(t_vector p)
{
	t_vector	nv;
	float		mod;

	mod = sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
	nv.x = p.x / mod;
	nv.y = p.y / mod;
	nv.z = p.z / mod;
	return (nv);
}

float	dot(t_vector v1, t_vector v2)
{
	float	dot_product;

	dot_product = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (dot_product);
}

t_vector	mult_vect(float t, t_vector v)
{
	t_vector	vector;

	vector.y = t * v.y;
	vector.x = t * v.x;
	vector.z = t * v.z;
	return (vector);
}

float	distance(t_vector p1, t_vector p2)
{
	float	d;

	d = sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * \
	(p2.y - p1.y) + (p2.z - p1.z) * (p2.z - p1.z));
	return (d);
}

t_vector	vector_cross_prodact(t_vector vector1, t_vector vector2)
{
	t_vector	result;

	result = vector_new(0, 0, 0);
	result.x = vector1.y * vector2.z - vector1.z * vector2.y;
	result.y = vector1.z * vector2.x - vector1.x * vector2.z;
	result.z = vector1.x * vector2.y - vector1.y * vector2.x;
	return (result);
}
