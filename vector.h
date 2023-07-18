#ifndef MINIRT_PROJECT_VECTOR_H
#define MINIRT_PROJECT_VECTOR_H

typedef struct s_vector
{
	double x;
	double y;
	double z;
} t_vector;

t_vector	*vector_new(double x, double y, double z);
t_vector	*vector_subtract(t_vector *v1, t_vector *v2);
t_vector	*vector_length(t_vector *v);
t_vector	*vector_normalize(t_vector *v);
t_vector    *vector_dot_product(t_vector *v1, t_vector *v2);

#endif //MINIRT_PROJECT_VECTOR_H
