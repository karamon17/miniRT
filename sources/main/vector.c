/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <gkhaishb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:17:22 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/08/01 17:05:40 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_vector	vector_new2(float x, float y, float z)
{
	t_vector	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
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

t_vector	vector_add2(t_vector v1, t_vector v2)
{
	t_vector	vector;

	vector.x = v1.x + v2.x;
	vector.y = v1.y + v2.y;
	vector.z = v1.z + v2.z;
	return (vector);
}

float	vect_len(t_vector v)
{
	float	length;

	length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return (length);
}

void	vector_normalize(t_vector v)
{
	float	length;

	length = vect_len(v);
	v.x = v.x / length;
	v.y = v.y / length;
	v.z = v.z / length;
}
