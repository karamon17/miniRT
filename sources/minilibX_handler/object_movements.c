/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <gkhaishb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:17:47 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/08/01 16:21:05 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	move_object(t_data *data, t_vector direction)
{
	if (data->checker.object_light_toggle)
		move_figure(data, direction);
	else
		move_light(data, direction);
}

void	move_figure(t_data *data, t_vector direction)
{
	if (data->closest_figure == NULL)
		return ;
	move_vector(&data->closest_figure->center, direction, 1);
}
