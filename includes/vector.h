#ifndef MINIRT_PROJECT_VECTOR_H
#define MINIRT_PROJECT_VECTOR_H

typedef struct s_vector
{
	float x;
	float y;
	float z;
} t_vector;

t_vector	*vector_new(float x, float y, float z);
t_vector	*vector_subtract(t_vector *v1, t_vector *v2);
float vector_length(t_vector *v);
void vector_normalize(t_vector *v);
float   vector_dot_product(t_vector *v1, t_vector *v2);
t_vector *multiply_vector(float t, t_vector *v);
t_vector *add_vector(t_vector *vector1, t_vector *vector2);
t_vector *vector_cross_prodact(t_vector *vector1, t_vector *vector2);
t_vector	*vector_dup(t_vector *v1);

#endif //MINIRT_PROJECT_VECTOR_H
