#include "../includes/miniRT.h"

static int		solve_cylinder(float x[2], t_vector *o, t_vector *d, t_figure *cylinder)
{
	t_vector *v;
	t_vector *u;
	t_vector *temp_v;
	t_vector *temp_u;
	t_vector *temp_o;
	float	a;
	float	b;
	float	c;
	t_vector *center;
	t_vector *normal;
	float	radius;

	center = cylinder->center;
	normal = cylinder->figure_body.cylinder.normal;
	radius = cylinder->figure_body.cylinder.radius;
	v = multiply_vector(vector_dot_product(d, normal), normal);
	temp_v = v;
	v = vector_subtract(d, v);
	free(temp_v);
	temp_v = vector_subtract(o, center);
	u = multiply_vector(vector_dot_product(temp_v, normal), normal);
	free(temp_v);
	temp_u = u;
	temp_o = vector_subtract(o, center);
	u = vector_subtract(temp_o, u);
	free(temp_u);
	free(temp_o);
	a = vector_dot_product(v, v);
	b = 2 * vector_dot_product(v, u);
	c = vector_dot_product(u, u) - radius * radius;
	x[0] = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	x[1] = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
	if ((x[0] != x[0] && x[1] != x[1]) || (x[0] < EPSILON && x[1] < EPSILON))
	{
		x[0] = INFINITY;
		x[1] = INFINITY;
		free(u);
		free(v);
		return (0);
	}
	free(u);
	free(v);
	return (1);
}

static t_vector calc_cy_normal(float x2[2], t_vector *o, t_vector *d, t_figure *cylinder)
{
	float	dist;
	float	x;
	t_vector *center = cylinder->center;
	t_vector *normal = cylinder->figure_body.cylinder.normal;
	float height = cylinder->figure_body.cylinder.height;
	t_vector *temp_x;
	t_vector *temp_dist;
	t_vector *temp_center;
	t_vector *temp_x_dist;
	t_vector *temp_x_dist_center;
	t_vector temp;

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
	temp_x = multiply_vector(x, d);
	temp_dist = multiply_vector(dist, normal);
	temp_center = vector_subtract(center, o);
	temp_x_dist = vector_subtract(temp_x, temp_dist);
	temp_x_dist_center = vector_subtract(temp_x_dist, temp_center);
	temp = normalize2(*temp_x_dist_center);
	free(temp_x);
	free(temp_dist);
	free(temp_center);
	free(temp_x_dist);
	free(temp_x_dist_center);
	return (temp);
}

static float	cy_intersection(t_vector *o, t_vector *d, t_vector *cy_normal, t_figure *cylinder)
{
	float		x2[2];
	t_vector 	*center;
	t_vector 	*normal;
	float 		height;
	t_vector 	*temp_x;
	t_vector 	*temp_c;
	t_vector 	*temp_x_c;

	center = cylinder->center;
	normal = cylinder->figure_body.cylinder.normal;
	height = cylinder->figure_body.cylinder.height;
	if (solve_cylinder(x2, o, d, cylinder) == 0)
		return (INFINITY);
	temp_x = multiply_vector(x2[0], d);
	temp_c = vector_subtract(center, o);
	temp_x_c = vector_subtract(temp_x, temp_c);
	cylinder->figure_body.cylinder.dist1 = vector_dot_product(normal, temp_x_c);
	free(temp_x);
	free(temp_x_c);
	temp_x = multiply_vector(x2[1], d);
	temp_x_c = vector_subtract(temp_x, temp_c);
	cylinder->figure_body.cylinder.dist2 = vector_dot_product(normal, temp_x_c);
	free(temp_x);
	free(temp_c);
	free(temp_x_c)	;
	if (!((cylinder->figure_body.cylinder.dist1 >= 0 && cylinder->figure_body.cylinder.dist1 <= height
					&& x2[0] > EPSILON) || (cylinder->figure_body.cylinder.dist2 >= 0
					&& cylinder->figure_body.cylinder.dist2 <= height && x2[0] > EPSILON)))
		return (INFINITY);
	*cy_normal = calc_cy_normal(x2, o, d, cylinder);
	return (x2[0]);
}

static float	caps_intersection(t_vector *o, t_vector *d, t_figure *cylinder)
{
	float		id1;
	float		id2;
	t_vector 	*ip1;
	t_vector 	*ip2;
	t_vector	*c2;
	float		radius;
	float 		height;
	t_vector 	*normal;
	t_vector 	*temp_h;
	t_vector 	*temp_id;
	t_figure 	new_plane;
	t_figure 	new_plane2;

	normal = cylinder->figure_body.cylinder.normal;
	radius = cylinder->figure_body.cylinder.radius;
	height = cylinder->figure_body.cylinder.height;
	ip1 = NULL;
	ip2 = NULL;
	temp_h = multiply_vector(height, normal);
	c2 = vector_add(cylinder->center, temp_h);
	free(temp_h);
	new_plane.center = cylinder->center;
	new_plane.figure_body.plane.normal = normal;
	new_plane2.center = c2;
	new_plane2.figure_body.plane.normal = normal;
	id1 = plane_intercept(&new_plane, o, d);
	id2 = plane_intercept(&new_plane2, o, d);
	if (id1 < INFINITY || id2 < INFINITY)
	{
		temp_id = multiply_vector(id1, d);
		ip1 = vector_add(o, temp_id);
		free(temp_id);
		temp_id = multiply_vector(id2, d);
		ip2 = vector_add(o, temp_id);
		free(temp_id);
		if ((id1 < INFINITY && distance(ip1, cylinder->center) <= radius)
				&& (id2 < INFINITY && distance(ip2, c2) <= radius))
		{
			free(ip1);
			free(ip2);
			free(c2);
			return (id1 < id2 ? id1 : id2);
		}
		else if (id1 < INFINITY
						&& distance(ip1, cylinder->center) <= radius)
		{
			free(ip1);
			free(ip2);
			free(c2);
			return (id1);
		}
		else if (id2 < INFINITY && distance(ip2, c2) <= radius)
		{
			free(ip1);
			free(ip2);
			free(c2);
			return (id2);
		}
		free(ip1);
		free(ip2);
		free(c2);
		return (INFINITY);
	}
	free(ip1);
	free(ip2);
	free(c2);
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
		cylinder->normal = cylinder->figure_body.cylinder.normal;
		return (caps_inter);
	}
	return (INFINITY);
}