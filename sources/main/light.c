#include "../includes/miniRT.h"

float	compute_lighting(t_data *data, t_vectors *input, float s)
{
	t_abc		abc;
	t_light 	*cur;
	t_vectors 	t;

	cur = data->lights;
	abc.a = 0.0f;
	while (cur)
    {
		t.v1 = NULL;
		t.v2 = NULL;
        if (cur->type == 'A')
            abc.a += cur->intensity;
        else
		{
            if (cur->type == 'L')
                t.v1 = vector_subtract(cur->vector, input->v1);
            if (check_intersection(data->figures, input->v1, t.v1))
			{
                cur = cur->next;
				free(t.v1);
                continue;
            }
            abc.b = dot(input->v2, t.v1);
			if (abc.b > 0)
				abc.a += cur->intensity * abc.b / (vector_length(input->v2) * vector_length(t.v1));
			if (s != -1)
			{
				t.v3 = mult_vect(2 * dot(input->v2, t.v1), input->v2);
				t.v2 = vector_subtract(t.v3, t.v1);
				free(t.v3);
				abc.c = dot(t.v2, input->v4);
				if (abc.c > 0)
					abc.a += cur->intensity * pow(abc.c / (vector_length(t.v2) * vector_length(input->v4)), s);
			}
			help_free(t.v1, t.v2, NULL, NULL);
        }
        cur = cur->next;
    }
    return (abc.a);
}

