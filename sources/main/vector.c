#include "../includes/miniRT.h"

t_vector	*vector_new(float x, float y, float z)
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

float vector_length(t_vector *v)
{
	float   length;
	length = sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
	return (length);
}

void vector_normalize(t_vector *v)
{
	float   length;

	length = vector_length(v);
	v->x = v->x / length;
	v->y = v->y / length;
	v->z = v->z / length;
}

float  vector_dot_product(t_vector *v1, t_vector *v2)
{
	float   dot_product;

	dot_product = v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
	return (dot_product);
}

t_vector *multiply_vector(float t, t_vector *v)
{
	t_vector *vector;

	vector = malloc(sizeof(t_vector));
	if (!vector)
		return (NULL);
	vector->x = t * v->x;
	vector->y = t * v->y;
	vector->z = t * v->z;
	return (vector);
}

t_vector *add_vector(t_vector *vector1, t_vector *vector2) {
    t_vector *new_vector;

    new_vector = vector_new(vector1->x + vector2->x, vector1->y + vector2->y, vector1->z + vector2->z);
    return (new_vector);
}
