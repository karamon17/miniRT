/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <gkhaishb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:45:12 by vbudilov          #+#    #+#             */
/*   Updated: 2023/08/01 17:15:42 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_data	*init_data(char *input)
{
	t_data	*rt_data;

	rt_data = malloc(sizeof(t_data));
	rt_data->filename = input;
	rt_data->lights = NULL;
	rt_data->figures = NULL;
	rt_data->closest_figure = NULL;
	init_checker(rt_data);
	init_mlx_data(rt_data);
	init_move_data(rt_data);
	return (rt_data);
}

void	init_camera(t_data *data)
{
	t_vector		camera_position;
	t_vector		position;

	camera_position = data->camera->direction;
	position = data->camera->origin;
	data->camera->origin = vector_new(0, 0, 0);
	data->camera->direction = vector_new(0, 0, -1);
	data->camera->up_vector = vector_new(0, 1, 0);
	data->camera->right_vector = vector_cross_prodact(data->camera->up_vector,
			data->camera->direction);
	vector_normalize(data->camera->right_vector);
	vector_normalize(data->camera->up_vector);
	if (position.x != 0 || position.y != 0 || position.z != 0)
		move_camera(data, position, 1);
	adjast_camera(data, camera_position);
}

void	init_move_data(t_data *data)
{
	t_movement	*move;
	int			mod;

	mod = 1;
	move = malloc(sizeof(t_movement));
	move->up = vector_new(0, 1 * mod, 0);
	move->down = vector_new(0, -1 * mod, 0);
	move->left = vector_new(-1 * mod, 0, 0);
	move->right = vector_new(1 * mod, 0, 0);
	move->forward = vector_new(0, 0, -1 * mod);
	move->backward = vector_new(0, 0, 1 * mod);
	move->rotate_x_left = quaternion_new(cosf(0.1308995f),
			sinf(0.1308995f), 0, 0);
	move->rotate_x_right = quaternion_new(cosf(0.1308995f),
			-sinf(0.1308995f), 0, 0);
	move->rotate_y_left = quaternion_new(cosf(0.1308995f),
			0, sinf(0.1308995f), 0);
	move->rotate_y_right = quaternion_new(cosf(0.1308995f),
			0, -sinf(0.1308995f), 0);
	data->movement = move;
}

void	init_mlx_data(t_data *data)
{
	t_mlx_data	*mlx_data;
	int			height;
	int			width;

	height = 1000;
	width = 1000;
	mlx_data = malloc(sizeof(t_mlx_data));
	mlx_data->mlx = mlx_init();
	mlx_data->win = mlx_new_window(mlx_data->mlx, width, height, "miniRT");
	mlx_data->img = mlx_new_image(mlx_data->mlx, width, height);
	mlx_data->width = (float )width;
	mlx_data->height = (float )height;
	mlx_data->bpp = 32;
	mlx_data->size_line = 800 * 4;
	mlx_data->endian = 0;
	data->mlx_data = mlx_data;
}

void	init_checker(t_data *data)
{
	data->checker.camera_init = 0;
	data->checker.has_ambient = 0;
	data->checker.has_spot = 0;
	data->checker.has_object = 0;
	data->checker.object_light_toggle = 1;
}
