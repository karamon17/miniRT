#include "../includes/miniRT.h"

t_color	*color_multiply(t_color *color, float intecivity)
{
    t_color *res;

    res = malloc(sizeof(t_color));
    res->red = color->red * intecivity;
    res->green = color->green * intecivity;
    res->blue = color->blue * intecivity;
    res->red = res->red > 255 ? 255 : res->red;
    res->green = res->green > 255 ? 255 : res->green;
    res->blue = res->blue > 255 ? 255 : res->blue;
    return (res);
}

int color_to_int(t_color *color)
{
	int r;
	int g;
	int b;
	int t;
	int res;

	t = round(color->transparency);
	r = round(color->red);
	g = round(color->green);
	b = round(color->blue);
	res = (t << 24 | r << 16 | g << 8 | b);
	free(color);
	return (res);
}

t_color *color_new(float r, float g, float b) {
	t_color *color;

	color = malloc(sizeof(t_color));
	if (!color)
		return (NULL);
	color->transparency = 0;
	color->red = r;
	color->green = g;
	color->blue = b;
	return (color);
}

// void	help_free(t_vector *n, t_vector *p, t_vector *temp_n, t_vector *temp_m)
// {
// 	if (temp_n && temp_n != n)
// 		free(temp_n);
// 	if (n)
// 		free(n);
// 	if (p)
// 		free(p);
// 	if (temp_m)
// 		free(temp_m);
// }
void	help_get_color(t_vectors *t, t_figure *cl_fig, float *closest_dist, t_vector ray)
{
	t->v1 = mult_vect2(*closest_dist, ray);
	t->v2 = vector_subtract2(t->v1, cl_fig->center);
	t->v3 = t->v2;
	if (cl_fig->type == CYLINDER)
	{
		t->v4 = mult_vect2(cl_fig->body.cyl.height / 2, cl_fig->body.cyl.normal);
		t->v5 = vector_add2(t->v4, cl_fig->center);
		t->v2 = vector_subtract2(t->v1, t->v5);
		//help_free(t->v4, t->v5, NULL, NULL);
	}
}

int get_color(t_data *data, t_vector ray)
{
    t_color 	*color;
    float 		closest_dist;
    t_figure 	*cl_fig;
	t_vectors	t;

    cl_fig = closest_inters(data->figures, data->camera->origin, ray, &closest_dist);
    if (cl_fig && closest_dist != INFINITY)
    {
		help_get_color(&t, cl_fig, &closest_dist, ray);
        if (cl_fig->type == PLANE && cl_fig->body.plane.normal.z > 0)
			t.v2 = cl_fig->body.plane.normal;
		else if (cl_fig->type == PLANE && cl_fig->body.plane.normal.z <= 0)
			t.v2 = mult_vect2(-1, cl_fig->body.plane.normal);
		vector_normalize(t.v2);
		t.v4 = mult_vect2(data->camera->direction.z, ray);
		color = color_multiply(cl_fig->RGB_color, compute_lighting(data, &t, cl_fig->specular));
		//help_free(t.v2, t.v1, t.v3, t.v4);
		return(color_to_int(color));
    }
	else
    	return (color_to_int(color_new(0, 0, 0)));
}
