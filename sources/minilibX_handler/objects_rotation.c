#include "../../includes/miniRT.h"

void rotate_object(t_data *data, t_quaternion *direction)
{
	if (data->checker.object_light_toggle)
		rotate_figure(data, direction);
}

void rotate_figure(t_data *data, t_quaternion *direction)
{
	if (data->closest_figure == NULL || data->closest_figure->type == SPHERE)
		return;
	else if (data->closest_figure->type == PLANE)
		rotate_quaternion(data->closest_figure->body.plane.normal, direction);
	else if (data->closest_figure->type == CYLINDER)
		rotate_quaternion(data->closest_figure->body.cyl.normal, direction);
}