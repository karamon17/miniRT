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

int get_color(t_data *data, t_vector *ray)
{
    t_color *color;
    t_color *temp;
    float closest_dist = 0;
    t_figure *closest_figure = NULL;

    color = color_new(0, 0, 0);
    temp = color;
    closest_figure = ClosestIntersection(data->figures, data->camera->origin, ray, &closest_dist, &color);
    if (closest_figure && closest_dist != INFINITY)
    {
        t_vector *p = multiply_vector(closest_dist, ray);
        t_vector *n = vector_subtract(p, closest_figure->center);
		if (closest_figure->type == CYLINDER)
			n = vector_subtract(p, vector_add(multiply_vector(closest_figure->figure_body.cylinder.height / 2, closest_figure->figure_body.cylinder.normal), closest_figure->center));
        if (closest_figure->type == PLANE && closest_figure->figure_body.plane.normal->z > 0)
			n = closest_figure->figure_body.plane.normal;
		else if (closest_figure->type == PLANE && closest_figure->figure_body.plane.normal->z <= 0)
			n = multiply_vector(-1, closest_figure->figure_body.plane.normal);
		vector_normalize(n);
        temp = color_multiply(color, compute_lighting(data, p, n, multiply_vector(data->camera->direction->z, ray), closest_figure->specular));
    }
    return (color_to_int(temp));
}
