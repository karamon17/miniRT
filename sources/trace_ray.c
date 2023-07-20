#include "../includes/miniRT.h"


int get_color(t_scene *scene, t_vector *ray);

void ray_trace(void *mlx, void *win, t_scene *scene) {

	int mlx_x;
	int mlx_y = 0;

	float x_angle;
	float y_angle;
	float x_ray;
	float y_ray;
	int color;
	t_vector *ray;
	t_view_plane *vplane;
	vplane = view_plane_new(scene->height, scene->width, scene->camera->fov);
	y_angle = scene->height / 2;

	while(y_angle >= (scene->height / 2) * -1)
	{
		y_ray = y_angle * vplane->y_pixel;
		x_angle = (scene->width / 2) * -1;
		mlx_x = 0;
		while (x_angle <= scene->width / 2)
		{
			x_ray = x_angle * vplane->x_pixel;
			ray = vector_new(x_ray, y_ray, -1);
			vector_normalize(ray);
			color = 1;//get_color(scene, ray);
			mlx_pixel_put(mlx, win, mlx_x, mlx_y, color);
			free(ray);
			x_angle++;
			mlx_x++;
		}
		y_angle--;
		mlx_y++;
	}

}

/*int get_color(t_scene *scene, t_vector *ray) {

    int color;
    t_sphere *current_sphere;
    color = 0x000000;

    current_sphere = scene->sphere;
    while(current_sphere)
    {
        if (sphere_intercept(current_sphere, scene->camera, ray) == 1)
            color = current_sphere->color;
        current_sphere = current_sphere->next;
    }
	t_vector *p = multiply_vector(closest_dist, ray);
	if (closest_sphere)
	{
		t_vector *n = vector_subtract(p, closest_sphere->center);
		vector_normalize(n);
		color = color * compute_lighting(scene, p, n);
	}	
    return (color);

}*/

int sphere_intercept(t_sphere *sphere, t_camera *camera, t_vector *ray) {
	float b;
	float c;
	float discr;
	float dist_1;
	float dist_2;
	t_vector *oc;

	oc = vector_subtract(camera->origin, sphere->center);
	b = 2 * vector_dot_product(oc, ray);
	c = vector_dot_product(oc, oc) - (sphere->radius * sphere->radius);
	discr = b * b - (4 * c);
	if (discr < 0)
		return (0);
	dist_1 = (-b - sqrt(discr)) / 2;
	dist_2 = (-b + sqrt(discr)) / 2;
	free(oc);
    if (dist_2 == dist_1)
        return (2);
	else if (dist_1 > 0)
		return (1);
	return (0);
}

t_view_plane *view_plane_new(float height, float width, float fov)
{
	t_view_plane	*view_plane;
	float 			aspect_ratio;

	view_plane = malloc(sizeof(t_view_plane));
	if (!view_plane)
		return (NULL);
	aspect_ratio = width / height;
	view_plane->width = tan(fov / 2 * M_PI / 180) * 2;
	view_plane->height = view_plane->width / aspect_ratio;
	view_plane->x_pixel = view_plane->width / width;
	view_plane->y_pixel = view_plane->height / height;
	return (view_plane);
}