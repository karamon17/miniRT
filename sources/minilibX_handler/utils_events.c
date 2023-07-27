#include "../../includes/miniRT.h"

int	ft_exit(int keycode, void *f)
{
	(void)f;
	(void)keycode;
	exit(0);
}

t_figure *get_closest_intersection(t_figure *figure, t_vector *vector, t_vector *ray, float *closest_dist) {
	t_figure *closest_figure;
	float dist;

	closest_figure = NULL;
	while(figure)
	{
		if (figure->type == SPHERE)
			dist = sphere_intercept(figure, vector, ray);
		else if (figure->type == PLANE)
			dist = plane_intercept(figure, vector, ray);
		if ((dist > 0) && (dist < *closest_dist || closest_figure == NULL))
		{
			*closest_dist = dist;
			closest_figure = figure;
		}
		figure = figure->next;
	}
	return (closest_figure);
}

void get_object(t_data *data, int x, int y) {
	float closest_dist = 0;
	t_figure *closest_figure;

	t_view_plane *vplane = view_plane_new(data->mlx_data->height, data->mlx_data->width, data->camera->fov);
	float y_angle = data->mlx_data->height / 2.f - y;
	float x_angle = (data->mlx_data->width / 2.f * -1) + x;
	float y_ray = y_angle * vplane->y_pixel;
	float x_ray = x_angle * vplane->x_pixel;
	t_vector *ray = vector_new(x_ray , y_ray, -1);
	closest_figure = get_closest_intersection(data->figures, data->camera->origin, ray, &closest_dist);
	data->closest_figure = closest_figure;
}