#ifndef MINIRT_PROJECT_SPHERE_H
#define MINIRT_PROJECT_SPHERE_H

#include "miniRT.h"

typedef struct s_sphere
{
	t_vector	*center;
	float		radius;
} t_sphere;

t_sphere   *sphere_new(t_vector *center, float radius);

#endif //MINIRT_PROJECT_SPHERE_H
