/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <gkhaishb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:17:52 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/08/01 16:20:59 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	rotate_object(t_data *data, t_quaternion direction)
{
	if (data->checker.object_light_toggle)
		rotate_figure(data, direction);
}

void	rotate_figure(t_data *data, t_quaternion direction)
{
	if (data->closest_figure == NULL || data->closest_figure->type == SPHERE)
		return ;
	else if (data->closest_figure->type == PLANE)
		rotate_quaternion(&data->closest_figure->body.plane.normal, direction);
	else if (data->closest_figure->type == CYLINDER)
		rotate_quaternion(&data->closest_figure->body.cyl.normal, direction);
}
