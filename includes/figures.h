#ifndef FIGURES_H
# define FIGURES_H

# include "miniRT.h"
# include "light.h"
# include "vector.h"

typedef struct s_quaternion
{
	float	w;
	float	x;
	float	y;
	float	z;
}			t_quaternion;

union u_figures
{
	struct s_sphere
	{
		float		rad;
	} sphere;
	struct s_plane
	{
		t_vector	normal;
	} plane;
	struct s_cylinder
	{
		t_vector	normal;
		float		rad;
		float		height;
		float		dist1;
		float		dist2;
	} cyl;
};

typedef enum e_figures
{
	SPHERE,
	PLANE,
	CYLINDER,
}	t_figures_type;

typedef struct s_figures
{
	union u_figures		body;
	t_vector			center;
	float				specular;
	t_color				rgb_color;
	t_vector			normal;
	enum e_figures		type;
	struct s_figures	*next;
}					t_figure;

#endif
