#include "miniRT.h"

t_sphere   *sphere_new(t_vector *center, double radius)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (NULL);
	sphere->center = center;
	sphere->radius = radius;
	return (sphere);
}
