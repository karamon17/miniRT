#include "../../includes/miniRT.h"

void move_cam_forward(t_data *data)
{
    t_vector *new_origin;
    t_vector *up;

    up = vector_new(0, 10, 0);
    new_origin = add_vector(data->camera->origin, up);
    free(data->camera->origin);
    free(up);
    data->camera->origin = new_origin;
    ray_trace(data->mlx_data->mlx, data);
}

void move_cam_backward(t_data *data)
{
	t_vector *new_origin;

	new_origin = multiply_vector( -0.1f, data->camera->origin);
	data->camera->origin = new_origin;
}

void move_cam_up(t_data *data)
{
	t_vector *new_origin;

	new_origin = multiply_vector( 0.1f, data->camera->origin);
	data->camera->origin = new_origin;
}

void move_cam_down(t_data *data)
{
	t_vector *new_origin;

	new_origin = multiply_vector( -0.1f, data->camera->origin);
	data->camera->origin = new_origin;
}

