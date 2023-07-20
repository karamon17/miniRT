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
	float   transparency;
	float	red;
	float 	green;
	float 	blue;
} t_color;

int color_to_int(t_color *color);
t_color *int_to_color(int color);
int compute_color(int color, float intensity);
t_color *color_new(float r, float g, float b);

#endif
