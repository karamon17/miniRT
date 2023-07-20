#include "../includes/miniRT.h"

t_light  *light_new(t_vector *vector, char	type, float	intensity)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	if (!light)
		return (NULL);
	light->vector = vector;
	light->type = type;
	light->intensity = intensity;
	light->next = NULL;
	return (light);
}

float	compute_lighting(t_scene *scene, t_vector *p, t_vector *n)
{
    float	i;
	float n_dot_l;
	t_light *current;

	current = scene->lights;
	t_vector *l;
	i = 0.0;
	while (current)
	{
		if (current->type == 'a')
			i += current->intensity;
		else
		{
			if (current->type == 'p')
				l = vector_subtract(current->vector, p);
			else
				l = current->vector;
			n_dot_l = vector_dot_product(n, l);
			if (n_dot_l > 0)
            	i += current->intensity * n_dot_l / (vector_length(n) * vector_length(l));
		}
		current = current->next;
	}
    return (i);
}

int color_to_int(t_color *color)
{
	int r;
	int g;
	int b;

	r = (int)color->red;
	g = (int)color->green;
	b = (int)color->blue;
	return (r << 16 | g << 8 | b);
}

t_color *int_to_color(int color)
{
	t_color *c;

	c = malloc(sizeof(t_color));
	if (!c)
		return (NULL);
	c->red = (color >> 16) & 0xFF;
	c->green = (color >> 8) & 0xFF;
	c->blue = color & 0xFF;
	return (c);
}