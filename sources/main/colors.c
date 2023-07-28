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
    t_color 	*color;
    t_color 	*temp;
    float 		closest_dist;
    t_figure 	*closest_figure;
	t_vector 	*n;
	t_vector 	*p;
	t_vector 	*temp_n;
	t_vector *temp_m;
	t_vector *temp_a;

	closest_dist = 0;
	closest_figure = NULL;
    color = color_new(0, 0, 0);
    temp = color;
    closest_figure = closest_intersection(data->figures, data->camera->origin, ray, &closest_dist, &color);
    if (closest_figure && closest_dist != INFINITY)
    {
        p = multiply_vector(closest_dist, ray);
        n = vector_subtract(p, closest_figure->center);
		temp_n = n;
		if (closest_figure->type == CYLINDER)
		{
			temp_m = multiply_vector(closest_figure->figure_body.cylinder.height / 2, closest_figure->figure_body.cylinder.normal);
			temp_a = vector_add(temp_m, closest_figure->center);
			n = vector_subtract(p, temp_a);
			free(temp_n);
			free(temp_m);
			free(temp_a);
		}
        else if (closest_figure->type == PLANE && closest_figure->figure_body.plane.normal->z > 0)
		{
			n = vector_dup(closest_figure->figure_body.plane.normal);
			free(temp_n);
		}	
		else if (closest_figure->type == PLANE && closest_figure->figure_body.plane.normal->z <= 0)
		{
			n = multiply_vector(-1, closest_figure->figure_body.plane.normal);
			free(temp_n);
		}	
		vector_normalize(n);
		temp_m = multiply_vector(data->camera->direction->z, ray);
        temp = color_multiply(color, compute_lighting(data, p, n, temp_m, closest_figure->specular));
		//free(color); пока не понимаю почему если это фришить, то аборт происходит
		free(temp_m);
		free(n);
    }
    return (color_to_int(temp));
}
