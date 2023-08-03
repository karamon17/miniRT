/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_events_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <gkhaishb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:17:31 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/08/01 16:21:51 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	move_camera(t_data *data, t_vector direction, int is_positive)
{
	t_figure	*figure;

	figure = data->figures;
	while (figure)
	{
		move_obj_for_camera(&figure->center, direction, is_positive);
		figure = figure->next;
	}
	if (data->lights->type != 'L')
		move_obj_for_camera(&data->lights->next->vector, \
		direction, is_positive);
	else
		move_obj_for_camera(&data->lights->vector, direction, is_positive);
}

void	move_obj_for_camera(t_vector *figure_center,
							t_vector direction, int is_positive)
{
	float	speed;

	speed = 10.f;
	if (!is_positive)
	{
		figure_center->x += direction.x * speed;
		figure_center->y += direction.y * speed;
		figure_center->z += direction.z * speed;
	}
	else
	{
		figure_center->x -= direction.x * speed;
		figure_center->y -= direction.y * speed;
		figure_center->z -= direction.z * speed;
	}
}

void	work_with_camera(int keycode, t_data *data)
{
	if (is_camera_movement_key(keycode))
		press_camera_movement_keys(keycode, data);
	else if (is_camera_rotation_key(keycode))
		press_camera_rotation_keys(keycode, data);
}
