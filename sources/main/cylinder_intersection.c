#include "../includes/miniRT.h"

static int		solve_cylinder(float x[2], t_vector *o, t_vector *d, t_figure *cylinder)
{
	t_vectors t;
	t_abc	abc;
	t_vector *normal;
	float	radius;

	normal = cylinder->body.cyl.normal;
	radius = cylinder->body.cyl.rad;
	t.v1 = multiply_vector(vector_dot_product(d, normal), normal);
	t.v3 = t.v1;
	t.v1 = vector_subtract(d, t.v1);
	free(t.v3);
	t.v3 = vector_subtract(o, cylinder->center);
	t.v2 = multiply_vector(vector_dot_product(t.v3, normal), normal);
	free(t.v3);
	t.v4 = t.v2;
	t.v5 = vector_subtract(o, cylinder->center);
	t.v2 = vector_subtract(t.v5, t.v2);
	help_free(t.v4, t.v5, NULL, NULL);
	abc.a = vector_dot_product(t.v1, t.v1);
	abc.b = 2 * vector_dot_product(t.v1, t.v2);
	abc.c = vector_dot_product(t.v2, t.v2) - radius * radius;
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
	t->v2 = multiply_vector(dist, t->v7);
	t->v3 = vector_subtract(t->v6, o);
	t->v4 = vector_subtract(t->v1, t->v2);
	t->v5 = vector_subtract(t->v4, t->v3);
	help_free(t->v1, t->v2, t->v3, t->v4);
	temp = normalize2(*(t->v5));
	free(t->v5);
	return (temp);
}

static t_vector calc_cy_normal(float x2[2], t_vector *o, t_vector *d, t_figure *cyl)
{
	float	dist;
	float	x;
	float height = cyl->body.cyl.height;
	t_vectors t;

	t.v6 = cyl->center;
	t.v7 = cyl->body.cyl.normal;
	if ((cyl->body.cyl.dist1 >= 0 && cyl->body.cyl.dist1 <= height
				&& x2[0] > EPSILON) && (cyl->body.cyl.dist2 >= 0
				&& cyl->body.cyl.dist2 <= height && x2[1] > EPSILON))
	{
		dist = x2[0] < x2[1] ? cyl->body.cyl.dist1 : cyl->body.cyl.dist2;
		x = x2[0] < x2[1] ? x2[0] : x2[1];
	}
	else if (cyl->body.cyl.dist1 >= 0 && cyl->body.cyl.dist1 <= height && x2[0] > EPSILON)
	{
		dist = cyl->body.cyl.dist1;
		x = x2[0];
	}
	else
	{
		dist = cyl->body.cyl.dist2;
		x = x2[1];
	}
	x2[0] = x;
	t.v1 = multiply_vector(x, d);
	return (help_calc_cy_normal(&t, o, dist));
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
	t.v1 = multiply_vector(x2[0], d);
	t.v2 = vector_subtract(t.v4, o);
	t.v3 = vector_subtract(t.v1, t.v2);
	cyl->body.cyl.dist1 = vector_dot_product(t.v5, t.v3);
	help_free(t.v1, t.v3, NULL, NULL);
	t.v1 = multiply_vector(x2[1], d);
	t.v3 = vector_subtract(t.v1, t.v2);
	cyl->body.cyl.dist2 = vector_dot_product(t.v5, t.v3);
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
	t.v5 = multiply_vector(cyl->body.cyl.height, t.v4);
	t.v3 = vector_add(cyl->center, t.v5);
	new_plane->body.plane.normal = v4;
	new_plane->center = cyl->center;
	new_plane2->body.plane.normal = v4;
	new_plane2->center = t.v3;
	help_free(NULL, t.v5, NULL, NULL);
}

static float	caps_intersection(t_vector *o, t_vector *d, t_figure *cyl)
{
	float		id1;
	float		id2;
	t_vectors 	t;
	t_figure 	new_plane;
	t_figure 	new_plane2;

	t.v4 = cyl->body.cyl.normal;
	t.v1 = NULL;
	t.v2 = NULL;
	t.v5 = multiply_vector(cyl->body.cyl.height, t.v4);
	t.v3 = vector_add(cyl->center, t.v5);
	free(t.v5);
	ft_newplane(&new_plane, &new_plane2, t.v4, cyl);
	id1 = plane_intercept(&new_plane, o, d);
	id2 = plane_intercept(&new_plane2, o, d);
	free(new_plane2.center);
	if (id1 < INFINITY || id2 < INFINITY)
	{
		t.v6 = multiply_vector(id1, d);
		t.v1 = vector_add(o, t.v6);
		t.v7 = multiply_vector(id2, d);
		t.v2 = vector_add(o, t.v7);
		help_free(t.v6, t.v7, NULL, NULL);
		if ((id1 < INFINITY && distance(t.v1, cyl->center) <= cyl->body.cyl.rad)
				&& (id2 < INFINITY && distance(t.v2, t.v3) <= cyl->body.cyl.rad))
		{
			help_free(t.v1, t.v2, t.v3, NULL);
			return (id1 < id2 ? id1 : id2);
		}
		else if (id1 < INFINITY	&& distance(t.v1, cyl->center) <= cyl->body.cyl.rad)
		{
			help_free(t.v1, t.v2, t.v3, NULL);
			return (id1);
		}
		else if (id2 < INFINITY && distance(t.v2, t.v3) <= cyl->body.cyl.rad)
		{
			help_free(t.v1, t.v2, t.v3, NULL);
			return (id2);
		}
		help_free(t.v1, t.v2, t.v3, NULL);
		return (INFINITY);
	}
	help_free(t.v1, t.v2, t.v3, NULL);
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
