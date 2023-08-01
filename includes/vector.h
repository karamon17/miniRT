#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;

typedef struct s_vectors
{
	t_vector	v1;
	t_vector	v2;
	t_vector	v3;
	t_vector	v4;
	t_vector	v5;
	t_vector	v6;
	t_vector	v7;
}	t_vectors;

float		vect_len(t_vector v);
void		vector_normalize(t_vector v);
t_vector	vector_new(float x, float y, float z);
t_vector	vector_subtract(t_vector v1, t_vector v2);
float		dot(t_vector v1, t_vector v2);
t_vector	mult_vect(float t, t_vector v);
t_vector	vector_cross_prodact(t_vector vector1, t_vector vector2);

#endif //MINIRT_PROJECT_VECTOR_H
