#ifndef MINIRT_PROJECT_SPHERE_H
#define MINIRT_PROJECT_SPHERE_H

#include "miniRT.h"
#include "light.h"
#include "vector.h"

typedef struct s_sphere t_sphere;


typedef struct s_quaternion
{
	float w;
	float x;
	float y;
	float z;
} t_quaternion;

typedef union			u_figures
{
	struct s_sphere
	{
		float		radius;
	} sphere;
	struct s_plane
	{
		t_vector	*normal;
	} plane;
	struct s_cylinder
	{
		t_vector	*normal;
		float		radius;
		float		height;
		float		dist1;
		float		dist2;
	} cylinder;

} u_figures;

enum e_figures
{
	SPHERE,
	PLANE,
	CYLINDER,
} t_figures_type;

typedef struct		s_figures
{
	union u_figures figure_body;
    t_vector	*center;
	float		specular;
	t_color		*RGB_color;
	enum e_figures	type;
	struct s_figures* next;
}					t_figure;

t_sphere *sphere_new(t_vector *center, float radius);

#endif //MINIRT_PROJECT_SPHERE_H
