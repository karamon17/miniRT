#include "../../includes/miniRT.h"

void rotate_plane(t_figure *plane, t_quaternion *direction);

void rotate_object(t_data *data, t_quaternion *direction) {

	if(data->closest_figure == NULL || data->closest_figure->type == SPHERE)
		return;
	else if(data->closest_figure->type == PLANE)
		rotate_plane(data->closest_figure, direction);
}

void rotate_plane(t_figure *plane, t_quaternion *direction) {
	t_quaternion *plane_direction_q;
	t_quaternion rotation_conjugate;
	t_quaternion new_direction;

	plane_direction_q = quaternion_new(0, plane->figure_body.plane.normal->x, plane->figure_body.plane.normal->y, plane->figure_body.plane.normal->z);
	rotation_conjugate = conjugate(*direction);
	new_direction = multiply_quaternion(multiply_quaternion(*direction, *plane_direction_q), rotation_conjugate);
	quaternion_normalize(new_direction);
	plane->figure_body.plane.normal->x = new_direction.x;
	plane->figure_body.plane.normal->y = new_direction.y;
	plane->figure_body.plane.normal->z = new_direction.z;
}
