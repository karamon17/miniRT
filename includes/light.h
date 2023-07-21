#ifndef MINIRT_PROJECT_LIGHT_H
#define MINIRT_PROJECT_LIGHT_H

#include "miniRT.h"


typedef struct s_data t_data;

typedef struct t_color
{
	float 	red;
	float 	green;
	float 	blue;
} t_color;

typedef struct s_light
{
	t_vector		*vector;
	char			type;
	float			intensity;
	t_color			*RGB_color;
	struct s_light	*next;
} t_light;

t_light *new_ambient_light(t_data *data);

#endif
