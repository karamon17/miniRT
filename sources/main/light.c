#include "../includes/miniRT.h"

float	compute_lighting(t_data *data, t_vector *p, t_vector *n, t_vector *ray, float s)
{
    float	i;
	float n_dot_l;
	float r_dot_v;
	t_light *current;
	t_vector *r;
	t_vector *temp_r;
	t_vector *l;

	l = NULL;
	r = NULL;
	current = data->lights;
	i = 0.0f;
	while (current)
    {
        if (current->type == 'A')
            i += current->intensity;
        else
		{
            if (current->type == 'L')
                l = vector_subtract(current->vector, p);
            //тени
            //TODO change check_intersection FIXED
            if (check_intersection(data->figures, p, l))
			{
                current = current->next;
                continue;
            }
            //диффузность
            n_dot_l = vector_dot_product(n, l);
               if (n_dot_l > 0)
                   i += current->intensity * n_dot_l / (vector_length(n) * vector_length(l));
               //зеркальность
               if (s != -1)
			   {
					temp_r = multiply_vector(2 * vector_dot_product(n, l), n);
                   r = vector_subtract(temp_r, l);
				   free(temp_r);
                   r_dot_v = vector_dot_product(r, ray);
                   if (r_dot_v > 0)
                       i += current->intensity * pow(r_dot_v / (vector_length(r) * vector_length(ray)), s);
               }
			free(l); //если фришить l то почему-то появляются артефакты на цилиндре
			l = NULL;
			free(r);
			r = NULL;
        }
        current = current->next;
    }
	free(l);
	free(r);
    return (i);
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
