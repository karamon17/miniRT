/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <gkhaishb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:17:49 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/08/01 16:21:02 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	work_with_object(int keycode, t_data *data)
{
	if (is_object_movement_key(keycode))
		press_object_movement_keys(keycode, data);
	else if (is_object_rotation_key(keycode))
		press_object_rotation_keys(keycode, data);
}

int	press_object_movement_keys(int keycode, t_data *data)
{
	if (keycode == KEY_S)
		move_object(data, data->movement->down);
	else if (keycode == KEY_D)
		move_object(data, data->movement->right);
	else if (keycode == KEY_W)
		move_object(data, data->movement->up);
	else if (keycode == KEY_A)
		move_object(data, data->movement->left);
	else if (keycode == KEY_E)
		move_object(data, data->movement->forward);
	else if (keycode == KEY_Q)
		move_object(data, data->movement->backward);
	return (0);
}

void	press_object_rotation_keys(int keycode, t_data *data)
{
	if (keycode == KEY_Z)
		rotate_object(data, data->movement->rotate_y_left);
	else if (keycode == KEY_C)
		rotate_object(data, data->movement->rotate_y_right);
	else if (keycode == KEY_R)
		rotate_object(data, data->movement->rotate_x_left);
	else if (keycode == KEY_F)
		rotate_object(data, data->movement->rotate_x_right);
}
