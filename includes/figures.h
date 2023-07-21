#ifndef MINIRT_PROJECT_SPHERE_H
#define MINIRT_PROJECT_SPHERE_H

#include "miniRT.h"
#include "light.h"
#include "vector.h"

typedef struct s_sphere t_sphere;

typedef union			u_figures
{
	struct s_sphere
	{
		t_vector	*center;
		float		radius;
		float       color;
	} sphere;

} u_figures;

enum e_figures
{
	SPHERE,
	PLANE,
	SQUARE,
	CYLINDER,
	TRIANGLE
} t_figures_type;

typedef struct		s_figures
{
	union u_figures figure_body;
	float		specular;
	t_color		*RGB_color;
	enum e_figures	type;

	struct s_figures* next;
}					t_figure;

t_sphere *sphere_new(t_vector *center, float radius);

#endif //MINIRT_PROJECT_SPHERE_H
