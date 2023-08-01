/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <gkhaishb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:17:19 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/08/01 17:14:38 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	ray_trace(t_mlx_data *mlx_data, t_data *data)
{
	t_win_params	w_params;
	t_view_plane	*vplane;

	vplane = NULL;
	vplane = init_image_and_vplane(mlx_data, data, vplane);
	w_params.mlx_y = 0;
	w_params.y_angle = mlx_data->height / 2.f;
	while (w_params.y_angle > (mlx_data->height / 2.f) * -1)
	{
		w_params.y_ray = w_params.y_angle * vplane->y_pixel;
		w_params.x_angle = (mlx_data->width / 2.f) * -1;
		w_params.mlx_x = 0;
		while (w_params.x_angle < mlx_data->width / 2)
		{
			handle_x_raw(&w_params, vplane, mlx_data, data);
		}
		w_params.y_angle--;
		w_params.mlx_y++;
	}
	free(vplane);
	mlx_put_image_to_window(data->mlx_data->mlx,
		data->mlx_data->win, data->mlx_data->img, 0, 0);
}

void	handle_x_raw(t_win_params *w_params,
				t_view_plane *vplane, t_mlx_data *mlx_data, t_data *data)
{
	t_vector		ray;
	int				color;

	w_params->x_ray = w_params->x_angle * vplane->x_pixel;
	ray = vector_new(w_params->x_ray, w_params->y_ray, -1);
	vector_normalize(ray);
	color = get_color(data, ray);
	mlx_data->img_data[w_params->mlx_x + w_params->mlx_y
		* (int)mlx_data->width] = color;
	w_params->x_angle++;
	w_params->mlx_x++;
}

t_view_plane	*init_image_and_vplane(t_mlx_data *mlx_data,
					t_data *data, t_view_plane *vplane)
{
	mlx_data->img = mlx_new_image(mlx_data->mlx,
			(int)mlx_data->width, (int)mlx_data->height);
	mlx_data->img_data = (int *)mlx_get_data_addr(mlx_data->img,
			&mlx_data->bpp, &mlx_data->size_line, &mlx_data->endian);
	vplane = view_plane_new(mlx_data->height,
			mlx_data->width, data->camera->fov);
	return (vplane);
}
