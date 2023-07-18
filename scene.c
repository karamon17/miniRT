#include "miniRT.h"

t_scene *scene_new(t_camera *camera, t_sphere *sphere)
{
	t_scene *scene;

	scene = malloc(sizeof(t_scene));
	if (!scene)
		return (NULL);
	scene->camera = camera;
	scene->sphere = sphere;
	scene->width = 0;
	scene->height = 0;
	return (scene);
}