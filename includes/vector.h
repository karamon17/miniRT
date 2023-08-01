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

float vect_len(t_vector v);
void vector_normalize(t_vector v);
t_vector	vector_new2(float x, float y, float z);
t_vector	vector_subtract2(t_vector v1, t_vector v2);
t_vector	vector_add2(t_vector v1, t_vector v2);
float		dot2(t_vector v1, t_vector v2);
t_vector	mult_vect2(float t, t_vector v);
float		distance2(t_vector p1, t_vector p2);
t_vector	vector_cross_prodact2(t_vector vector1, t_vector vector2);

#endif //MINIRT_PROJECT_VECTOR_H
