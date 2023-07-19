#include "miniRT.h"

void ray_trace(void *mlx, void *win, t_scene *scene);

int main()
{
	void *mlx;
	void *win;
	mlx = mlx_init();

    //spheres
	t_vector *center = vector_new(1, 3, -20);
	t_vector *center2 = vector_new(-1, -5, -30);
	t_vector *center3 = vector_new(-3, -3, -17);
	t_sphere *yellow_sphere = sphere_new(center, 5, 0xFFFF00);
	t_sphere *green_sphere = sphere_new(center2, 5, 0x00FF00);
	t_sphere *blue_sphere = sphere_new(center3, 5, 0x0000FF);
    yellow_sphere->next = green_sphere;
    green_sphere->next = blue_sphere;

    //light
    /*t_vector *origin_light = vector_new(0, 50, -40);
    t_light *light = light_new(origin_light, 0.5f, POINT);
    (void ) light;*/
    //camera
	t_vector *origin = vector_new(0, 0, 0);
	t_vector *direction = vector_new(0, 0, -1);
	t_camera *camera = camera_new(origin, direction, 50);

    //scene
	t_scene *scene = scene_new(camera, yellow_sphere);
	scene->width = 800;
	scene->height = 600;
	win = mlx_new_window(mlx, scene->width, scene->height, "miniRT");
	ray_trace(mlx, win, scene);
	mlx_loop(mlx);
	return (0);
}
