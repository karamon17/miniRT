#include "../../includes/miniRT.h"

void press_camera_rotation_keys(int keycode, t_data *data) {
	if (keycode == KEY_1)
		rotate_quaternion(data->camera->direction, data->movement->rotate_y_left);
	else if (keycode == KEY_3)
		rotate_quaternion(data->camera->direction, data->movement->rotate_y_right);
	else if (keycode == KEY_5)
		rotate_quaternion(data->camera->direction, data->movement->rotate_x_left);
	else if (keycode == KEY_2)
		rotate_quaternion(data->camera->direction, data->movement->rotate_x_right);
}

void press_camera_movement_keys(int keycode, t_data *data) {

	if (keycode == KEY_UP_ARROW)
		move_vector(data->camera->origin, data->camera->up_vector, 0);
	else if (keycode == KEY_DOWN_ARROW)
        move_vector(data->camera->origin, data->camera->up_vector, 1);
	else if (keycode == KEY_LEFT_ARROW)
		move_vector(data->camera->origin, data->camera->right_vector, 1);
    else if (keycode == KEY_RIGHT_ARROW)
        move_vector(data->camera->origin, data->camera->right_vector, 0);
    else if ( keycode == KEY_PLUS)
        move_vector(data->camera->origin, data->camera->direction, 1);
    else if (keycode == KEY_MINUS)
        move_vector(data->camera->origin, data->camera->direction, 0);
   }


void work_with_camera(int keycode, t_data *data) {
	// t_camera *camera;
	// t_matrix_4 view;

	//camera = data->camera;
	//update_figures_positions(data, view);
	if(is_camera_movement_key(keycode))
		press_camera_movement_keys(keycode, data);
	else if(is_camera_rotation_key(keycode))
		press_camera_rotation_keys(keycode, data);
	// camera->right_vector = vector_cross_prodact(camera->direction, camera->up_vector);
	// camera->up_vector = vector_cross_prodact(camera->right_vector, camera->direction);
	// view = view_matrix(camera->origin, camera->direction, camera->up_vector);
	// update_figures_positions(data, view);
}

void update_figures_positions(t_data *data, t_matrix_4 matrix4) {
	t_figure *figure;

	figure = data->figures;
	while (figure) {
		multiply_matrix_vector(matrix4, figure->center);
		figure = figure->next;
	}
}

t_matrix_4 view_matrix(t_vector *camera_position, t_vector *camera_direction, t_vector *up_vector)
{
	t_vector *temp;
	t_vector view_dir;
	t_vector right_dir;
	t_vector *up_dir;
	t_matrix_4 result;
	
	temp = vector_subtract(camera_direction, camera_position);
	view_dir = get_vector_normalize(temp);
	free(temp);
	temp = vector_cross_prodact(up_vector, &view_dir);
	right_dir = get_vector_normalize(temp);
	free(temp);
	up_dir = vector_cross_prodact(&view_dir, &right_dir);

	result.matrix[0][0] = right_dir.x;
	result.matrix[0][1] = up_dir->x;
	result.matrix[0][2] = -view_dir.x;
	result.matrix[0][3] = -vector_dot_product(&right_dir, camera_position);

	result.matrix[1][0] = right_dir.y;
	result.matrix[1][1] = up_dir->y;
	result.matrix[1][2] = -view_dir.y;
	result.matrix[1][3] = -vector_dot_product(up_dir, camera_position);

	result.matrix[2][0] = right_dir.z;
	result.matrix[2][1] = up_dir->z;
	result.matrix[2][2] = -view_dir.z;
	result.matrix[2][3] = -vector_dot_product(&view_dir, camera_position);

	result.matrix[3][0] = 0;
	result.matrix[3][1] = 0;
	result.matrix[3][2] = 0;
	result.matrix[3][3] = 1;
	free(up_dir);
	return result;
}

t_vector get_vector_normalize(t_vector *vector) {
	float length = sqrtf(vector->x * vector->x + vector->y * vector->y + vector->z * vector->z);
	t_vector result;
	result.x = vector->x / length;
	result.y = vector->y / length;
	result.z = vector->z / length;
	return result;
}

void multiply_matrix_vector(t_matrix_4 view, t_vector *object) {
	float x = object->x * view.matrix[0][0] + object->y * view.matrix[0][1] + object->z * view.matrix[0][2] + view.matrix[0][3];
	float y = object->x * view.matrix[1][0] + object->y * view.matrix[1][1] + object->z * view.matrix[1][2] + view.matrix[1][3];
	float z = object->x * view.matrix[2][0] + object->y * view.matrix[2][1] + object->z * view.matrix[2][2] + view.matrix[2][3];
	object->x = x;
	object->y = y;
	object->z = z;
}
