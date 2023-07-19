#include "../includes/miniRT.h"

int main()
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    t_vector *center = vector_new(10, 50, -50);
    t_vector *center2 = vector_new(-10, -50, -100);
    t_sphere *sphere = sphere_new(center, 20, 1000);
    t_sphere *sphere2 = sphere_new(center2, 50, 100660);
    sphere->next = sphere2;
    t_vector *origin = vector_new(0, 0, 0);
    t_vector *direction = vector_new(0, 0, -1);
    t_camera *camera = camera_new(origin, direction, 140);
    t_scene *scene = scene_new(camera, sphere);
    scene->width = 800;
    scene->height = 600;
    win = mlx_new_window(mlx, scene->width, scene->height, "miniRT");
    ray_trace(mlx, win, scene);
    mlx_loop(mlx);
    return (0);
}
