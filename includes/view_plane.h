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
int sphere_intercept(t_sphere *sphere, t_vector *vector, t_vector *ray);
void ray_trace(void *mlx, void *win, t_scene *scene);
#endif //MINIRT_PROJECT_VIEW_PLANE_H
