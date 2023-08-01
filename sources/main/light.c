/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <gkhaishb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:16:22 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/08/01 18:42:31 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

float	ft_specular(t_vector l, t_vectors *input, t_light *cur, t_abc *abc)
{
	t_vector	r;
	float		res;

	res = 0;
	if (abc->b != -1)
	{
		r = vector_subtract(mult_vect(2 * dot(input->v2, l), \
			input->v2), l);
		abc->c = dot(r, input->v4);
		// if (round(pow(abc->c / (vect_len(r) \
		// 	* vect_len(input->v4)), abc->b)) != 0)
		// 	printf("%f\n", pow(abc->c / (vect_len(r) \
		// 		* vect_len(input->v4)), abc->b));
		if (abc->c > 0)
			res = cur->intensity * pow(abc->c / (vect_len(r) \
			* vect_len(input->v4)), abc->b);
	}
	if (round(res) != 0)
		printf ("%f\n", res);
	return (res);
}

float	compute_lighting(t_data *data, t_vectors *input, float s)
{
	t_abc		abc;
	t_light		*cur;
	t_vector	l;

	cur = data->lights;
	abc.a = 0.0f;
	while (cur)
	{
		if (cur->type == 'A')
			abc.a += cur->intensity;
		if (cur->type == 'L')
		{
			l = vector_subtract(cur->vector, input->v1);
			if (check_intersection(data->figures, input->v1, l))
			{
				cur = cur->next;
				continue ;
			}
			if (dot(input->v2, l) > 0)
				abc.a += cur->intensity * dot(input->v2, l) / \
				(vect_len(input->v2) * vect_len(l));
			abc.b = s;
			abc.a += ft_specular(l, input, cur, &abc);
		}
		cur = cur->next;
	}
	return (abc.a);
}
