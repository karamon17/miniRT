/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:45:20 by vbudilov          #+#    #+#             */
/*   Updated: 2023/08/01 13:45:21 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_light	*new_ambient_light(t_data *data)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	light->type = 'A';
	if (data->lights == NULL)
		data->lights = light;
	else
		data->lights->next = light;
	light->next = NULL;
	return (light);
}

t_light	*new_spot_light(t_data *data)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	light->type = 'L';
	if (data->lights == NULL)
		data->lights = light;
	else
		data->lights->next = light;
	light->next = NULL;
	data->checker.has_spot++;
	return (light);
}

t_camera	*new_camera(t_data *data)
{
	t_camera	*camera;

	camera = malloc(sizeof(t_camera));
	camera->next = NULL;
	data->checker.camera_init++;
	return (camera);
}

t_quaternion	*quaternion_new(float i, float i1, float i2, float i3)
{
	t_quaternion	*quaternion;

	quaternion = malloc(sizeof(t_quaternion));
	quaternion->w = i;
	quaternion->x = i1;
	quaternion->y = i2;
	quaternion->z = i3;
	return (quaternion);
}

void	adjast_camera(t_data *data, t_vector camera_position,
					t_quaternion *rotate)
{
	if (camera_position.y == -1)
		rotate_camera(data, (rotate = quaternion_new(0.7071f, 0.7071f, 0, 0)));
	else if (camera_position.y == 1)
		rotate_camera(data, (rotate = quaternion_new(0.7071f, -0.7071f, 0, 0)));
	else if (camera_position.x == -1)
		rotate_camera(data, (rotate = quaternion_new(0.7071f, 0, 0.7071f, 0)));
	else if (camera_position.x == 1)
		rotate_camera(data, (rotate = quaternion_new(0.7071f, 0, -0.7071f, 0)));
	else if (camera_position.z == 1)
	{
		rotate_camera(data, (rotate = quaternion_new(0.7071f, 0, -0.7071f, 0)));
		free(rotate);
		rotate_camera(data, (rotate = quaternion_new(0.7071f, 0, -0.7071f, 0)));
	}
	free(rotate);
}
