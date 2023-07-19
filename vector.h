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

#endif //MINIRT_PROJECT_VECTOR_H
