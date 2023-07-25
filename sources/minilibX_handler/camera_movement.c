#include "../../includes/miniRT.h"

void move_cam(t_data *data, t_vector *direction) {

    t_vector *new_origin;

    new_origin = add_vector(data->camera->origin, direction);
    free(data->camera->origin);
    data->camera->origin = new_origin;
    ray_trace(data->mlx_data->mlx, data);
}

void rotate_cam(t_data *data, t_vector *direction) {
    t_vector *new_direction;

    new_direction = add_vector(data->camera->direction, direction);
    free(data->camera->direction);
    data->camera->direction = new_direction;
    ray_trace(data->mlx_data->mlx, data);
}