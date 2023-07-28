#include "../../includes/miniRT.h"

void move_light(t_data *data, t_vector *direction) {
    if(data->lights->type == 'A')
        return;
    else if(data->lights->type == 'L')
        move_vector(*(data->lights->vector), *direction);
}

void rotate_light(t_data *data, t_quaternion *direction) {
    if(data->lights->type == 'A')
        return;
    else if(data->lights->type == 'L')
        rotate_quaternion(data->lights->vector, direction);
}


