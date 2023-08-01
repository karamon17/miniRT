#ifndef MINIRT_PROJECT_LIGHT_H
#define MINIRT_PROJECT_LIGHT_H

#include "miniRT.h"
#include "vector.h"

typedef struct s_data t_data;

typedef struct t_color
{
	float 	red;
	float 	green;
	float 	blue;
	float   transparency;
} t_color;

typedef struct s_light
{
	t_vector		vector;
	char			type;
	float			intensity;
	t_color			*RGB_color;
	struct s_light	*next;
} t_light;

t_light *new_ambient_light(t_data *data);

int color_to_int(t_color *color);
t_color *color_new(float r, float g, float b);

#endif