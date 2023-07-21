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
float	compute_lighting(t_scene *scene, t_vector *p, t_vector *n, t_vector *ray, float s);
t_sphere *ClosestIntersection(t_sphere *sphere, t_vector *vector, t_vector *ray, float *closest_dist, t_color **color);
t_sphere *check_intersection(t_sphere *sphere, t_vector *vector, t_vector *ray);

#endif //MINIRT_PROJECT_MINIRT_H
