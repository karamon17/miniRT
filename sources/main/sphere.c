#include "../includes/miniRT.h"

t_sphere *sphere_new(t_vector *center, float radius, t_color *color, float specular)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (NULL);
	sphere->center = center;
	sphere->radius = radius;
    sphere->RGB_color = color;
	sphere->specular = specular;
    sphere->next = NULL;
	return (sphere);
}
