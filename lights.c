#include "miniRT.h"

t_light new_light(t_vector *position, float brightness, t_light_type type)
{
    t_light light;

    light.position = position;
    light.brightness = brightness;
    light.type = type;
    return (light);
}

void clamp_color(t_color *color)
{
    if (color->r > 255)
        color->r = 255;
    if (color->g > 255)
        color->g = 255;
    if (color->b > 255)
        color->b = 255;
}
