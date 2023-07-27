#include "../../includes/miniRT.h"

void move_object(t_data *data, t_vector *direction) {
    if(data->checker.object_light_toggle)
        move_figure(data, direction);
    else
        move_light(data, direction);
}

void move_figure(t_data *data, t_vector *direction) {
    if(data->closest_figure == NULL)
        return ;
    if(data->closest_figure->type == SPHERE)
        move_vector(data->closest_figure->figure_body.sphere.center, direction);
    else if(data->closest_figure->type == PLANE)
        move_vector(data->closest_figure->figure_body.plane.center, direction);
/*	else if(data->closest_figure->type == CYLINDER)
		move_cylinder(data->closest_figure->object, direction);*/
}