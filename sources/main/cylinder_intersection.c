#include "../includes/miniRT.h"

void	help_solve_cylinder(t_abc	*abc, t_vectors *t, t_figure *cyl)
{
	abc->a = dot(t->v1, t->v1);
	abc->b = 2 * dot(t->v1, t->v2);
	abc->c = dot(t->v2, t->v2) - cyl->body.cyl.rad * cyl->body.cyl.rad;
}

static int		solve_cylinder(float x[2], t_vector *o, t_vector *d, t_figure *cyl)
{
	t_vectors 	t;
	t_abc		abc;

	t.v1 = mult_vect(dot(d, cyl->body.cyl.normal), cyl->body.cyl.normal);
	t.v3 = t.v1;
	t.v1 = vector_subtract(d, t.v1);
	free(t.v3);
	t.v3 = vector_subtract(o, cyl->center);
	t.v2 = mult_vect(dot(t.v3, cyl->body.cyl.normal), cyl->body.cyl.normal);
	t.v4 = t.v2;
	t.v5 = vector_subtract(o, cyl->center);
	t.v2 = vector_subtract(t.v5, t.v2);
	help_free(t.v4, t.v5, t.v3, NULL);
	help_solve_cylinder(&abc, &t, cyl);
	x[0] = (-abc.b + sqrt(abc.b * abc.b - 4 * abc.a * abc.c)) / (2 * abc.a);
	x[1] = (-abc.b - sqrt(abc.b * abc.b - 4 * abc.a * abc.c)) / (2 * abc.a);
	help_free(t.v1, t.v2, NULL, NULL);
	if ((x[0] != x[0] && x[1] != x[1]) || (x[0] < EPSILON && x[1] < EPSILON))
	{
		x[0] = INFINITY;
		x[1] = INFINITY;
		return (0);
	}
	return (1);
}

t_vector	help_calc_cy_normal(t_vectors *t, t_vector *o, float dist)
{
	t_vector temp;
	t->v2 = mult_vect(dist, t->v7);
	t->v3 = vector_subtract(t->v6, o);
	t->v4 = vector_subtract(t->v1, t->v2);
	t->v5 = vector_subtract(t->v4, t->v3);
	help_free(t->v1, t->v2, t->v3, t->v4);
	temp = normalize2(*(t->v5));
	free(t->v5);
	return (temp);
}

void	help_calc(t_vectors *t, float *height, t_figure *cyl)
{
	*height = cyl->body.cyl.height;
	t->v6 = cyl->center;
	t->v7 = cyl->body.cyl.normal;
}

static t_vector calc_cy_normal(float x2[2], t_vector *o, t_vector *d, t_figure *cyl)
{
	t_abc		abc;
	t_vectors 	t;

	help_calc(&t, &abc.c, cyl);
	if ((cyl->body.cyl.dist1 >= 0 && cyl->body.cyl.dist1 <= abc.c
				&& x2[0] > EPSILON) && (cyl->body.cyl.dist2 >= 0
				&& cyl->body.cyl.dist2 <= abc.c && x2[1] > EPSILON))
	{
		abc.a = x2[0] < x2[1] ? cyl->body.cyl.dist1 : cyl->body.cyl.dist2;
		abc.b = x2[0] < x2[1] ? x2[0] : x2[1];
	}
	else if (cyl->body.cyl.dist1 >= 0 && cyl->body.cyl.dist1 <= abc.c && x2[0] > EPSILON)
	{
		abc.a = cyl->body.cyl.dist1;
		abc.b = x2[0];
	}
	else
	{
		abc.a = cyl->body.cyl.dist2;
		abc.b = x2[1];
	}
	x2[0] = abc.b;
	t.v1 = mult_vect(abc.b, d);
	return (help_calc_cy_normal(&t, o, abc.a));
}

static float	cy_intersection(t_vector *o, t_vector *d, t_vector *cy_normal, t_figure *cyl)
{
	float		x2[2];
	float 		height;
	t_vectors 	t;

	t.v4 = cyl->center;
	t.v5 = cyl->body.cyl.normal;
	height = cyl->body.cyl.height;
	if (solve_cylinder(x2, o, d, cyl) == 0)
		return (INFINITY);
	t.v1 = mult_vect(x2[0], d);
	t.v2 = vector_subtract(t.v4, o);
	t.v3 = vector_subtract(t.v1, t.v2);
	cyl->body.cyl.dist1 = dot(t.v5, t.v3);
	help_free(t.v1, t.v3, NULL, NULL);
	t.v1 = mult_vect(x2[1], d);
	t.v3 = vector_subtract(t.v1, t.v2);
	cyl->body.cyl.dist2 = dot(t.v5, t.v3);
	help_free(t.v1, t.v2, t.v3, NULL);
	if (!((cyl->body.cyl.dist1 >= 0 && cyl->body.cyl.dist1 <= height
					&& x2[0] > EPSILON) || (cyl->body.cyl.dist2 >= 0
					&& cyl->body.cyl.dist2 <= height && x2[0] > EPSILON)))
		return (INFINITY);
	*cy_normal = calc_cy_normal(x2, o, d, cyl);
	return (x2[0]);
}

void	ft_newplane(t_figure *new_plane, t_figure *new_plane2, t_vector *v4, t_figure *cyl)
{
	t_vectors 	t;

	t.v4 = cyl->body.cyl.normal;
	t.v5 = mult_vect(cyl->body.cyl.height, t.v4);
	t.v3 = vector_add(cyl->center, t.v5);
	new_plane->body.plane.normal = v4;
	new_plane->center = cyl->center;
	new_plane2->body.plane.normal = v4;
	new_plane2->center = t.v3;
	free(t.v5);
}

void	help_caps(t_vectors *t, t_abc *id, t_figure *cyl, t_vector *d)
{
	t->v5 = mult_vect(cyl->body.cyl.height, cyl->body.cyl.normal);
	t->v3 = vector_add(cyl->center, t->v5);
	t->v6 = mult_vect(id->a, d);
	t->v7 = mult_vect(id->b, d);
}

void	help_caps2(t_vectors *t, t_abc *ab, t_figure *cyl, t_vector *o)
{
	t->v1 = vector_add(o, t->v6);
	t->v2 = vector_add(o, t->v7);
	ab->a = distance(t->v1, cyl->center);
	ab->b = distance(t->v2, t->v3);
	help_free(t->v6, t->v7, t->v5, NULL);
	help_free(t->v1, t->v2, t->v3, NULL);
}

static float	caps_intersection(t_vector *o, t_vector *d, t_figure *cyl)
{
	t_abc		id;
	t_abc		ab;
	t_vectors 	t;
	t_figure 	new_plane;
	t_figure 	new_plane2;

	ft_newplane(&new_plane, &new_plane2, cyl->body.cyl.normal, cyl);
	id.a = plane_intercept(&new_plane, o, d);
	id.b = plane_intercept(&new_plane2, o, d);
	free(new_plane2.center);
	if (id.a < INFINITY || id.b < INFINITY)
	{
		help_caps(&t, &id, cyl, d);
		help_caps2(&t, &ab, cyl, o);
		if ((id.a < INFINITY && ab.a <= cyl->body.cyl.rad)
				&& (id.b < INFINITY && ab.b <= cyl->body.cyl.rad))
			return (id.a < id.b ? id.a : id.b);
		else if (id.a < INFINITY	&& ab.a <= cyl->body.cyl.rad)
			return (id.a);
		else if (id.b < INFINITY && ab.b <= cyl->body.cyl.rad)
			return (id.b);
	}
	return (INFINITY);
}

float	cylinder_intersection(t_vector *o, t_vector *d, t_figure *cylinder)
{
	float	cylinder_inter;
	float	caps_inter;
	t_vector cy_normal;

	cylinder_inter = cy_intersection(o, d, &cy_normal, cylinder);
	caps_inter = caps_intersection(o, d, cylinder);
	if (cylinder_inter < INFINITY || caps_inter < INFINITY)
	{
		if (cylinder_inter < caps_inter)
		{
			cylinder->normal = &cy_normal;
			return (cylinder_inter);
		}
		cylinder->normal = cylinder->body.cyl.normal;
		return (caps_inter);
	}
	return (INFINITY);
}
