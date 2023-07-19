#ifndef MINIRT_PROJECT_MINIRT_H
#define MINIRT_PROJECT_MINIRT_H

#include "vector.h"
#include "unistd.h"
#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "sphere.h"
#include "camera.h"
#include "light.h"
#include "scene.h"
#include "view_plane.h"
#include "mlx.h"

t_light  *light_new(t_vector *vector, char	type, float	intensity);
float	compute_lighting(t_scene *scene, t_vector *p, t_vector *n);

#endif //MINIRT_PROJECT_MINIRT_H
