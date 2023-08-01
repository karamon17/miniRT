#include "../../includes/miniRT.h"

void move_light(t_data *data, t_vector *direction) {
    if(data->lights->type == 'L')
        move_vector(data->lights->vector, direction, 1);
    else
        move_vector(data->lights->next->vector, direction, 1);
}

/*void rotate_light(t_data *data, t_quaternion *direction) {
    if(data->lights->type == 'L')
        rotate_quaternion(data->lights->vector, direction);
    else
        rotate_quaternion(data->lights->next->vector, direction);
}*/

