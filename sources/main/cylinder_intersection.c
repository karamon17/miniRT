#include "../includes/miniRT.h"

static int		solve_cylinder(double x[2], t_vector *o, t_vector *d, t_figure *cylinder)
{
	t_vector *v;
	t_vector *u;
	double	a;
	double	b;
	double	c;
	t_vector *center = cylinder->center;
	t_vector *normal = cylinder->figure_body.cylinder.normal;
	float	radius = cylinder->figure_body.cylinder.radius;

	v = multiply_vector(vector_dot_product(d, normal), normal);
	v = vector_subtract(d, v);
	u = multiply_vector(vector_dot_product(vector_subtract(o, center), normal),
													normal);
	u = vector_subtract(vector_subtract(o, center), u);
	a = vector_dot_product(v, v);
	b = 2 * vector_dot_product(v, u);
	c = vector_dot_product(u, u) - pow(radius, 2);
	x[0] = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
	x[1] = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
	if ((x[0] != x[0] && x[1] != x[1]) || (x[0] < EPSILON && x[1] < EPSILON))
	{
		x[0] = INFINITY;
		x[1] = INFINITY;
		return (0);
	}
	return (1);
}

static t_vector calc_cy_normal(double x2[2], t_vector *o, t_vector *d, t_figure *cylinder)
{
	double	dist;
	double	x;
	t_vector *center = cylinder->center;
	t_vector *normal = cylinder->figure_body.cylinder.normal;
	float height = cylinder->figure_body.cylinder.height;

	if ((cylinder->figure_body.cylinder.dist1 >= 0 && cylinder->figure_body.cylinder.dist1 <= height
				&& x2[0] > EPSILON) && (cylinder->figure_body.cylinder.dist2 >= 0
				&& cylinder->figure_body.cylinder.dist2 <= height && x2[1] > EPSILON))
	{
		dist = x2[0] < x2[1] ? cylinder->figure_body.cylinder.dist1 : cylinder->figure_body.cylinder.dist2;
		x = x2[0] < x2[1] ? x2[0] : x2[1];
	}
	else if (cylinder->figure_body.cylinder.dist1 >= 0 && cylinder->figure_body.cylinder.dist1 <= height
														&& x2[0] > EPSILON)
	{
		dist = cylinder->figure_body.cylinder.dist1;
		x = x2[0];
	}
	else
	{
		dist = cylinder->figure_body.cylinder.dist2;
		x = x2[1];
	}
	x2[0] = x;
	return (normalize2(*vector_subtract(vector_subtract(multiply_vector(x, d),
			multiply_vector(dist, normal)), vector_subtract(center, o))));
}

static double	cy_intersection(t_vector *o, t_vector *d, t_vector *cy_normal, t_figure *cylinder)
{
	double	x2[2];
	t_vector *center = cylinder->center;
	t_vector *normal = cylinder->figure_body.cylinder.normal;
	float height = cylinder->figure_body.cylinder.height;

	if (solve_cylinder(x2, o, d, cylinder) == 0)
		return (INFINITY);
	cylinder->figure_body.cylinder.dist1 = vector_dot_product(normal, vector_subtract(multiply_vector(x2[0], d),
												vector_subtract(center, o)));
	cylinder->figure_body.cylinder.dist2 = vector_dot_product(normal, vector_subtract(multiply_vector(x2[1], d),
												vector_subtract(center, o)));
	if (!((cylinder->figure_body.cylinder.dist1 >= 0 && cylinder->figure_body.cylinder.dist1 <= height
					&& x2[0] > EPSILON) || (cylinder->figure_body.cylinder.dist2 >= 0
					&& cylinder->figure_body.cylinder.dist2 <= height && x2[0] > EPSILON)))
		return (INFINITY);
	*cy_normal = calc_cy_normal(x2, o, d, cylinder);
	return (x2[0]);
}

static double	caps_intersection(t_vector *o, t_vector *d, t_figure *cylinder)
{
	double	id1;
	double	id2;
	t_vector *ip1;
	t_vector *ip2;
	t_vector *c2;
	t_vector *center = cylinder->center;
	t_vector *normal = cylinder->figure_body.cylinder.normal;
	float	radius = cylinder->figure_body.cylinder.radius;
	float height = cylinder->figure_body.cylinder.height;

	c2 = vector_add(center, multiply_vector(height, normal));
	t_figure new_plane;
	new_plane.center = center;
	new_plane.figure_body.plane.normal = normal;
	t_figure new_plane2;
	new_plane2.center = c2;
	new_plane2.figure_body.plane.normal = normal;
	id1 = plane_intercept(&new_plane, o, d);
	id2 = plane_intercept(&new_plane2, o, d);
	if (id1 < INFINITY || id2 < INFINITY)
	{
		ip1 = vector_add(o, multiply_vector(id1, d));
		ip2 = vector_add(o, multiply_vector(id2, d));
		if ((id1 < INFINITY && distance(ip1, center) <= radius)
				&& (id2 < INFINITY && distance(ip2, c2) <= radius))
			return (id1 < id2 ? id1 : id2);
		else if (id1 < INFINITY
						&& distance(ip1, center) <= radius)
			return (id1);
		else if (id2 < INFINITY && distance(ip2, c2) <= radius)
			return (id2);
		return (INFINITY);
	}
	return (INFINITY);
}

double			cylinder_intersection(t_vector *o, t_vector *d, t_figure *cylinder)
{
	double	cylinder_inter;
	double	caps_inter;
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
		cylinder->normal = cylinder->figure_body.cylinder.normal;
		return (caps_inter);
	}
	return (INFINITY);
}