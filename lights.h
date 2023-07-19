#ifndef MINIRT_LIGHTS_H
#define MINIRT_LIGHTS_H

#include "miniRT.h"

typedef enum e_light_type
{
    AMBIENT,
    POINT,
    DIRECTIONAL
} t_light_type;

typedef struct s_light
{
    t_light_type type;
    t_vector	*position;
    float		brightness;
} t_light;

t_light *light_new(t_vector *origin, float brightness, t_light_type type);

#endif //MINIRT_LIGHTS_H
