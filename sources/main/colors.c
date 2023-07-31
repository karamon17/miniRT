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

void	help_free(t_vector *n, t_vector *p, t_vector *temp_n, t_vector *temp_m)
{
	if (temp_n != n)
		free(temp_n);
	free(n);
	free(p);
	free(temp_m);
}

int get_color(t_data *data, t_vector *ray)
{
    t_color 	*color;
    float 		closest_dist;
    t_figure 	*cl_fig;
	t_vectors	t;

    cl_fig = closest_intersection(data->figures, data->camera->origin, ray, &closest_dist);
    if (cl_fig && closest_dist != INFINITY)
    {
		t.v1 = multiply_vector(closest_dist, ray);
        t.v2 = vector_subtract(t.v1, cl_fig->center);
		t.v3 = t.v2;
		if (cl_fig->type == CYLINDER)
		{
			t.v4 = multiply_vector(cl_fig->body.cyl.height / 2, cl_fig->body.cyl.normal);
			t.v5 = vector_add(t.v4, cl_fig->center);
			t.v2 = vector_subtract(t.v1, t.v5);
			help_free(t.v4, t.v5, NULL, NULL);
		}
        else if (cl_fig->type == PLANE && cl_fig->body.plane.normal->z > 0)
			t.v2 = vector_dup(cl_fig->body.plane.normal);
		else if (cl_fig->type == PLANE && cl_fig->body.plane.normal->z <= 0)
			t.v2 = multiply_vector(-1, cl_fig->body.plane.normal);
		vector_normalize(t.v2);
		t.v4 = multiply_vector(data->camera->direction->z, ray);
		color = color_multiply(cl_fig->RGB_color, compute_lighting(data, t.v1, t.v2, t.v4, cl_fig->specular));
		help_free(t.v2, t.v1, t.v3, t.v4);
		return(color_to_int(color));
    }
	else
    	return (color_to_int(color_new(0, 0, 0)));
}
