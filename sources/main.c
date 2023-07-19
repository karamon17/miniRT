#include "../includes/miniRT.h"

int main()
{
	void *mlx;
	void *win;
	mlx = mlx_init();

    //spheres
	t_vector *center = vector_new(3, 7, -20);
	t_vector *center2 = vector_new(4, -5, -30);
	t_vector *center3 = vector_new(-3, -3, -17);
	t_sphere *yellow_sphere = sphere_new(center, 5, 0xFFFF00);
	t_sphere *green_sphere = sphere_new(center2, 5, 0x00FF00);
	t_sphere *blue_sphere = sphere_new(center3, 5, 0x0000FF);
    yellow_sphere->next = green_sphere;
    green_sphere->next = blue_sphere;

    //light
    t_vector *point_light = vector_new(-7, 10, 5);
    t_light *light1 = light_new(point_light, 'p', 0.6);
	t_vector *directional_light = vector_new(20, 20, 0);
	t_light *light2 = light_new(directional_light, 'd', 0.2);
	light1->next = light2;
	t_light *light3 = light_new(NULL, 'a', 0.2);
	light2->next = light3;

    //camera
	t_vector *origin = vector_new(0, 0, 0);
	t_vector *direction = vector_new(0, 0, -1);
	t_camera *camera = camera_new(origin, direction, 90);

    //scene
	t_scene *scene = scene_new(camera, yellow_sphere, light1);
	scene->width = 800;
	scene->height = 600;
	win = mlx_new_window(mlx, scene->width, scene->height, "miniRT");
	ray_trace(mlx, win, scene);
	mlx_loop(mlx);
	return (0);
}
