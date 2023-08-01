/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <gkhaishb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:17:57 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/08/01 16:20:47 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	ft_exit(int keycode, void *f)
{
	(void) f;
	(void) keycode;
	exit(0);
}

void	get_object(t_data *data, int x, int y)
{
	t_win_params	w_params;
	float			closest_dist;
	t_figure		*closest_figure;
	t_view_plane	*vplane;
	t_vector		ray;

	closest_dist = 0;
	vplane = view_plane_new(data->mlx_data->height,
			data->mlx_data->width, data->camera->fov);
	w_params.y_angle = data->mlx_data->height / 2.f - y;
	w_params.x_angle = (data->mlx_data->width / 2.f * -1) + x;
	w_params.y_ray = w_params.y_angle * vplane->y_pixel;
	w_params.x_ray = w_params.x_angle * vplane->x_pixel;
	ray = vector_new2(w_params.x_ray,
			w_params.y_ray, -1);
	closest_figure = closest_inters(data->figures,
			data->camera->origin, ray, &closest_dist);
	data->closest_figure = closest_figure;
	free(vplane);
}
