#include "../../includes/miniRT.h"

void move_object(t_data *data, t_vector *direction) {

	if(data->closest_figure == NULL)
		return;
	if(data->closest_figure->type == SPHERE)
		move_sphere(data->closest_figure, direction);
	else if(data->closest_figure->type == PLANE)
		move_plane(data->closest_figure, direction);
/*	else if(data->closest_figure->type == CYLINDER)
		move_cylinder(data->closest_figure->object, direction);*/
}

void move_plane(t_figure *figure, t_vector *direction) {
	figure->figure_body.plane.center->x += direction->x;
	figure->figure_body.plane.center->y += direction->y;
	figure->figure_body.plane.center->z += direction->z;
}

void move_sphere(t_figure *sphere, t_vector *direction) {
	sphere->figure_body.sphere.center->x += direction->x;
	sphere->figure_body.sphere.center->y += direction->y;
	sphere->figure_body.sphere.center->z += direction->z;
}