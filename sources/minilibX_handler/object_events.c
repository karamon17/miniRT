#include "../../includes/miniRT.h"

int	press_object_movement_keys(int keycode, t_data *data)
{
	if (keycode == KEY_S)
		move_object(data, data->movement->down);
	else if (keycode == KEY_D)
		move_object(data, data->movement->right);
	else if (keycode == KEY_W)
		move_object(data, data->movement->up);
	else if (keycode == KEY_A)
		move_object(data, data->movement->left);
	else if (keycode == KEY_E)
		move_object(data, data->movement->forward);
	else if (keycode == KEY_Q)
		move_object(data, data->movement->backward);
	return (0);
}

void move_object(t_data *data, t_vector *direction) {

	if(data->closest_figure == NULL)
		return;
	if(data->closest_figure->type == SPHERE)
		move_sphere(data->closest_figure, direction);
/*	else if(data->closest_figure->type == PLANE)
		move_plane(data->closest_figure->object, direction);
	else if(data->closest_figure->type == SQUARE)
		move_square(data->closest_figure->object, direction);
	else if(data->closest_figure->type == CYLINDER)
		move_cylinder(data->closest_figure->object, direction);*/
}

void move_sphere(t_figure *sphere, t_vector *direction) {
	sphere->figure_body.sphere.center->x += direction->x;
	sphere->figure_body.sphere.center->y += direction->y;
	sphere->figure_body.sphere.center->z += direction->z;

}
