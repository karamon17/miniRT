#include "../includes/miniRT.h"


int main()
{
	void *mlx;
	void *win;
	mlx = mlx_init();

    //spheres
	t_color *color = color_new(255, 0, 0);
	t_color *color2 = color_new(0, 255, 0);
	t_color *color3 = color_new(0, 0, 255);
	t_vector *center = vector_new(-230, -230, -900);
	t_vector *center2 = vector_new(230, 230, -900);
	t_vector *center3 = vector_new(230, -230, -900);
	t_sphere *red_sphere = sphere_new(center, 200, color, -1);
	t_sphere *green_sphere = sphere_new(center2, 200, color2, -1);
	t_sphere *blue_sphere = sphere_new(center3, 200, color3, -1);
    red_sphere->next = green_sphere;
    green_sphere->next = blue_sphere;

    //light
    t_vector *point_light = vector_new(-300, 200, -300);
    t_light *light1 = light_new(point_light, 'p', 0.0f);
	//t_vector *directional_light = vector_new(70, 20, 0);
	//t_light *light2 = light_new(directional_light, 'd', 0.0f);
	//light1->next = light2;
	t_light *light3 = light_new(NULL, 'a', 0.8f);
	light1->next = light3;

    //camera
	t_vector *origin = vector_new(0, 0, 0);
	t_vector *direction = vector_new(0, 0, -1);
	t_camera *camera = camera_new(origin, direction, 70);

    //scene
	t_scene *scene = scene_new(camera, red_sphere, light1);
	scene->width = 800;
	scene->height = 600;
	win = mlx_new_window(mlx, scene->width, scene->height, "miniRT");
	ray_trace(mlx, win, scene);
	mlx_loop(mlx);
	return (0);
}

