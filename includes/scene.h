#ifndef MINIRT_PROJECT_SCENE_H
#define MINIRT_PROJECT_SCENE_H

#include "miniRT.h"

typedef struct s_scene
{
	t_camera	*camera;
	t_sphere	*sphere;
	float       width;
	float       height;
} t_scene;

t_scene *scene_new(t_camera *camera, t_sphere *sphere);

#endif //MINIRT_PROJECT_SCENE_H
