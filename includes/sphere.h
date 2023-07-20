#ifndef MINIRT_PROJECT_SPHERE_H
#define MINIRT_PROJECT_SPHERE_H

#include "miniRT.h"
#include "light.h"

typedef struct s_sphere t_sphere;

typedef struct s_sphere
{
	t_vector	*center;
	float		radius;
    float      color;
	float		specular;
	t_color		*RGB_color;
    t_sphere  *next;
} t_sphere;

t_sphere *sphere_new(t_vector *center, float radius, t_color *color, float specular);

#endif //MINIRT_PROJECT_SPHERE_H
