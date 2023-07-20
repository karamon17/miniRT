#ifndef MINIRT_PROJECT_SPHERE_H
#define MINIRT_PROJECT_SPHERE_H

#include "miniRT.h"

typedef struct s_sphere t_sphere;

typedef struct s_sphere
{
	t_vector	*center;
	float		radius;
    float      color;
    t_sphere  *next;
} t_sphere;

typedef struct t_plane t_plane;
typedef struct t_square t_square;
typedef struct t_cylinder t_cylinder;
typedef struct t_triangle t_triangle;

typedef union			u_figures
{
	t_sphere	*sp;
	t_plane		*pl;
	t_square	*sq;
	t_cylinder	*cy;
	t_triangle	*tr;
} u_figures;

typedef struct		s_figures
{
	int				flag;
	union u_figures	fig;
	int				color;
	int				specular;
	double			refl_idx;
	double			refr_idx;
	int				texture;
	double			wavelength;
	struct s_figures*next;
}					t_figures;

t_sphere *sphere_new(t_vector *center, float radius, int color);

#endif //MINIRT_PROJECT_SPHERE_H
