#ifndef MINIRT_PROJECT_LIGHT_H
#define MINIRT_PROJECT_LIGHT_H

#include "miniRT.h"

typedef struct s_light
{
	t_vector		*vector;
	char			type;
	float			intensity;
	struct s_light	*next;
} t_light;

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
} t_color;

#endif
