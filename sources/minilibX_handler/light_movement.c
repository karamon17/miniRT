/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <gkhaishb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:17:39 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/08/01 16:17:40 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	move_light(t_data *data, t_vector direction)
{
	if (data->lights->type == 'L')
		move_vector(&data->lights->vector, direction, 1);
	else
		move_vector(&data->lights->next->vector, direction, 1);
}
