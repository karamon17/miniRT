#ifndef MINIRT_PROJECT_VIEW_PLANE_H
#define MINIRT_PROJECT_VIEW_PLANE_H

#include "miniRT.h"

typedef struct s_view_plane
{
	float 		height;
	float 		width;
	float 		x_pixel;
	float 		y_pixel;
	float		fov;
} t_view_plane;

t_view_plane  *view_plane_new(float height, float width, float fov);
float sphere_intercept(t_figure *sphere, t_vector *vector, t_vector *ray);
void ray_trace(void *mlx, t_data *data);
float plane_intercept(t_figure *plane, t_vector *vector, t_vector *ray);
float	cylinder_intercept(t_figure *cylinder, t_vector *vector, t_vector *ray);

#endif //MINIRT_PROJECT_VIEW_PLANE_H
