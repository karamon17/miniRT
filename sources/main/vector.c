/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <gkhaishb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:17:22 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/08/01 16:17:23 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_vector	*vector_new(float x, float y, float z)
{
	t_vector	*vector;

	vector = malloc(sizeof(t_vector));
	if (!vector)
		return (NULL);
	vector->x = x;
	vector->y = y;
	vector->z = z;
	return (vector);
}

t_vector	vector_new2(float x, float y, float z)
{
	t_vector	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

t_vector	*vector_subtract(t_vector *v1, t_vector *v2)
{
	t_vector	*vector;

	vector = malloc(sizeof(t_vector));
	if (!vector)
		return (NULL);
	vector->x = v1->x - v2->x;
	vector->y = v1->y - v2->y;
	vector->z = v1->z - v2->z;
	return (vector);
}

t_vector	vector_subtract2(t_vector v1, t_vector v2)
{
	t_vector	vector;

	vector.x = v1.x - v2.x;
	vector.y = v1.y - v2.y;
	vector.z = v1.z - v2.z;
	return (vector);
}

t_vector	*vector_add(t_vector *v1, t_vector *v2)
{
	t_vector	*vector;

	vector = malloc(sizeof(t_vector));
	if (!vector)
		return (NULL);
	vector->x = v1->x + v2->x;
	vector->y = v1->y + v2->y;
	vector->z = v1->z + v2->z;
	return (vector);
}

t_vector	vector_add2(t_vector v1, t_vector v2)
{
	t_vector	vector;

	vector.x = v1.x + v2.x;
	vector.y = v1.y + v2.y;
	vector.z = v1.z + v2.z;
	return (vector);
}

t_vector	*vector_dup(t_vector *v1)
{
	t_vector	*vector;

	vector = malloc(sizeof(t_vector));
	if (!vector)
		return (NULL);
	vector->x = v1->x;
	vector->y = v1->y;
	vector->z = v1->z;
	return (vector);
}

float vect_len(t_vector v)
{
	float   length;
	length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return (length);
}

void vector_normalize(t_vector v)
{
	float   length;

	length = vect_len(v);
	v.x = v.x / length;
	v.y = v.y / length;
	v.z = v.z / length;
}

t_vector	normalize2(t_vector p)
{
	t_vector	nv;
	float	mod;

	mod = sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
	nv.x = p.x / mod;
	nv.y = p.y / mod;
	nv.z = p.z / mod;
	return (nv);
}

float  dot(t_vector *v1, t_vector *v2)
{
	float   dot_product;

	dot_product = v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
	return (dot_product);
}

float  dot2(t_vector v1, t_vector v2)
{
	float   dot_product;

	dot_product = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (dot_product);
}

t_vector *mult_vect(float t, t_vector *v)
{
	t_vector *vector;

	vector = malloc(sizeof(t_vector));
	if (!vector)
		return (NULL);
	vector->x = t * v->x;
	vector->y = t * v->y;
	vector->z = t * v->z;
	return (vector);
}

t_vector mult_vect2(float t, t_vector v)
{
	t_vector vector;

	vector.y = t * v.y;
	vector.x = t * v.x;
	vector.z = t * v.z;
	return (vector);
}

float		distance(t_vector *p1, t_vector *p2)
{
	float d;

	d = sqrt((p2->x - p1->x) * (p2->x - p1->x) + (p2->y - p1->y) * (p2->y - p1->y) + (p2->z - p1->z) * (p2->z - p1->z));
	return (d);
}

float		distance2(t_vector p1, t_vector p2)
{
	float d;

	d = sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y) + (p2.z - p1.z) * (p2.z - p1.z));
	return (d);
}

t_vector *add_vector(t_vector *vector1, t_vector *vector2) {
    t_vector *new_vector;

    new_vector = vector_new(vector1->x + vector2->x, vector1->y + vector2->y, vector1->z + vector2->z);
    return (new_vector);
}

t_vector *vector_cross_prodact(t_vector *vector1, t_vector *vector2) {
	t_vector *result;

	result = vector_new(0,0,0);
	result->x = vector1->y * vector2->z - vector1->z * vector2->y;
	result->y = vector1->z * vector2->x - vector1->x * vector2->z;
	result->z = vector1->x * vector2->y - vector1->y * vector2->x;
	return (result);
}

t_vector vector_cross_prodact2(t_vector vector1, t_vector vector2) {
	t_vector result;

	result = vector_new2(0,0,0);
	result.x = vector1.y * vector2.z - vector1.z * vector2.y;
	result.y = vector1.z * vector2.x - vector1.x * vector2.z;
	result.z = vector1.x * vector2.y - vector1.y * vector2.x;
	return (result);
}