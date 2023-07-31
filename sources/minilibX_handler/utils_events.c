#include "../../includes/miniRT.h"

int	ft_exit(int keycode, void *f)
{
	(void)f;
	(void)keycode;
	exit(0);
}

void get_object(t_data *data, int x, int y){
	float closest_dist = 0;
	t_figure *closest_figure;

	t_view_plane *vplane = view_plane_new(data->mlx_data->height, data->mlx_data->width, data->camera->fov);
	float y_angle = data->mlx_data->height / 2.f - y;
	float x_angle = (data->mlx_data->width / 2.f * -1) + x;
	float y_ray = y_angle * vplane->y_pixel;
	float x_ray = x_angle * vplane->x_pixel;
	t_vector *ray = vector_new(x_ray , y_ray, -1);
	closest_figure = closest_intersection(data->figures, data->camera->origin, ray, &closest_dist);
	data->closest_figure = closest_figure;
	free(ray);
	free(vplane);
}