#include "../../includes/miniRT.h"

void press_camera_rotation_keys(int keycode, t_data *data) {
	if (keycode == KEY_1)
		rotate_camera(data, data->movement->rotate_y_right);
	else if (keycode == KEY_3)
		rotate_camera(data, data->movement->rotate_y_left);
	else if (keycode == KEY_5)
		rotate_camera(data, data->movement->rotate_x_right);
	else if (keycode == KEY_2)
		rotate_camera(data, data->movement->rotate_x_left);
}

void rotate_camera(t_data *data, t_quaternion *direction) {

	t_figure *figure;

	figure = data->figures;
	while(figure)
	{
		if(figure->type == SPHERE)
			rotate_figure_for_camera(data, figure->center, direction);
		else if(figure->type == PLANE)
			rotate_figure_for_camera(data, figure->figure_body.plane.normal, direction);
		else if(figure->type == CYLINDER) {
			t_vector *temp_h = multiply_vector(figure->figure_body.cylinder.height, figure->figure_body.cylinder.normal);
			t_vector *c = vector_add(figure->center, temp_h);
			rotate_figure_for_camera(data, c, direction);
			figure->center = vector_subtract(c, temp_h);
			free(c);
			free(temp_h);
		}
		figure = figure->next;
	}
	if(data->lights->type != 'L')
		rotate_figure_for_camera(data, data->lights->next->vector, direction);
	else
		rotate_figure_for_camera(data, data->lights->vector, direction);
}

void rotate_figure_for_camera(t_data *data, t_vector *figure_center, t_quaternion *direction) {
	//t_vector rotation_point = *data->camera->origin;
	(void)data;
	//vector_subtract(figure_center, &rotation_point);
	rotate_quaternion(figure_center, direction);
	//vector_add(figure_center, &rotation_point);
}
void press_camera_movement_keys(int keycode, t_data *data) {

	if (keycode == KEY_UP_ARROW)
		move_camera(data, data->camera->up_vector, 1);
	else if (keycode == KEY_DOWN_ARROW)
		move_camera(data, data->camera->up_vector, 0);
	else if (keycode == KEY_LEFT_ARROW)
		move_camera(data, data->camera->right_vector, 0);
    else if (keycode == KEY_RIGHT_ARROW)
        move_camera(data, data->camera->right_vector, 1);
    else if ( keycode == KEY_PLUS)
        move_camera(data, data->camera->direction, 0);
    else if (keycode == KEY_MINUS)
        move_camera(data, data->camera->direction, 1);
   }

void move_camera(t_data *data, t_vector *direction, int is_positive) {
	t_figure *figure;

	figure = data->figures;
	while (figure) {
		move_obj_for_camera(figure->center, direction, is_positive);
		figure = figure->next;
	}
	if(data->lights->type != 'L')
		move_obj_for_camera(data->lights->next->vector, direction, is_positive);
	else
		move_obj_for_camera(data->lights->vector, direction, is_positive);
}

void move_obj_for_camera(t_vector *figure_center, t_vector *direction, int is_positive) {
	float speed = 10.f;
	if(!is_positive)
	{
		figure_center->x += direction->x * speed;
		figure_center->y += direction->y * speed;
		figure_center->z += direction->z * speed;
	}
	else
	{
		figure_center->x -= direction->x * speed;
		figure_center->y -= direction->y * speed;
		figure_center->z -= direction->z * speed;
	}
}


void work_with_camera(int keycode, t_data *data) {

	if(is_camera_movement_key(keycode))
		press_camera_movement_keys(keycode, data);
	else if(is_camera_rotation_key(keycode))
		press_camera_rotation_keys(keycode, data);
}