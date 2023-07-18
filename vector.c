#include "miniRT.h"

t_vector	*vector_new(double x, double y, double z)
{
	t_vector	*vector;

	vector = malloc(sizeof(t_vector));
	if (!vector)
		return (NULL);
	vector->x = x;
	vector->y = y;
	vector->z = z;
	return (vector);
}

t_vector	*vector_subtract(t_vector *v1, t_vector *v2)
{
	t_vector	*vector;

	vector = malloc(sizeof(t_vector));
	if (!vector)
		return (NULL);
	vector->x = v1->x - v2->x;
	vector->y = v1->y - v2->y;
	vector->z = v1->z - v2->z;
	return (vector);
}

t_vector	*vector_length(t_vector *v)
{
	t_vector	*vector;

	vector = malloc(sizeof(t_vector));
	if (!vector)
		return (NULL);
	vector->x = v->x * v->x;
	vector->y = v->y * v->y;
	vector->z = v->z * v->z;
	return (vector);
}

t_vector	*vector_normalize(t_vector *v)
{
	t_vector	*vector;
	double		length;

	vector = malloc(sizeof(t_vector));
	if (!vector)
		return (NULL);
	length = sqrt(vector_length(v)->x + vector_length(v)->y + vector_length(v)->z);
	vector->x = v->x / length;
	vector->y = v->y / length;
	vector->z = v->z / length;
	return (vector);
}

