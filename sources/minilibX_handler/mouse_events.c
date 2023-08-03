/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <gkhaishb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:17:41 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/08/01 16:17:43 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	mouse_handle(int button, int x, int y, t_data *data)
{
	(void) data;
	if (button == LEFT_CLICK)
	{
		get_object(data, x, y);
	}
	return (1);
}
