#include "../includes/miniRT.h"

void	ft_specular(t_vectors 	*t, t_vectors *input, t_light 	*cur, t_abc *abc)
{
	if (abc->b != -1)
	{
		t->v3 = mult_vect2(2 * dot2(input->v2, t->v1), input->v2);
		t->v2 = vector_subtract2(t->v3, t->v1);
		//free(t->v3);
		abc->c = dot2(t->v2, input->v4);
		if (abc->c > 0)
			abc->a += cur->intensity * pow(abc->c / (vect_len(t->v2) * vect_len(input->v4)), abc->b);
	}
	//help_free(t->v1, t->v2, NULL, NULL);
}
void	ft_ambient(t_vectors *t, t_light *cur, t_abc *abc)
{
	//t->v1 = NULL;
	//t->v2 = ;
	(void)t;
	if (cur->type == 'A')
		abc->a += cur->intensity;
}

float	compute_lighting(t_data *data, t_vectors *input, float s)
{
	t_abc		abc;
	t_light 	*cur;
	t_vectors 	t;

	cur = data->lights;
	abc.a = 0.0f;
	while (cur)
    {
		ft_ambient(&t, cur, &abc);
        if (cur->type == 'L')
		{
            t.v1 = vector_subtract2(cur->vector, input->v1);
            if (check_intersection(data->figures, input->v1, t.v1))
			{
                cur = cur->next;
				//free(t.v1);
                continue;
            }
            abc.b = dot2(input->v2, t.v1);
			if (abc.b > 0)
				abc.a += cur->intensity * abc.b / (vect_len(input->v2) * vect_len(t.v1));
			abc.b = s;
			ft_specular(&t, input, cur, &abc);
        }
        cur = cur->next;
    }
    return (abc.a);
}

