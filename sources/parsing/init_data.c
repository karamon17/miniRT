#include "../../includes/miniRT.h"

t_data *init_data(char *input) {

	t_data *rt_data;

	rt_data = malloc(sizeof(t_data));
	rt_data->filename = input;
	rt_data->lights = NULL;
	rt_data->figures = NULL;
    rt_data->closest_figure = NULL;
	init_checker(rt_data);
	init_mlx_data(rt_data);
	init_move_data(rt_data);
	return (rt_data);
}

void init_camera(t_data *data) {

	if(data->camera->direction->z == -1 || data->camera->direction->z == 1)
		data->camera->up_vector = vector_new(0, 1, 0);
	else if(data->camera->direction->x == -1 || data->camera->direction->x == 1)
		data->camera->up_vector = vector_new(0, 0, 1);
	else if(data->camera->direction->y == -1 || data->camera->direction->y == 1)
		data->camera->up_vector = vector_new(0, 0, 1);
	else
		data->camera->up_vector = vector_new(0, 1, 0);
	data->camera->right_vector = vector_cross_prodact(data->camera->up_vector, data->camera->direction);
}

void init_move_data(t_data *data) {

	t_movement *move;
	int mod;

	mod = 50;
	move = malloc(sizeof(t_movement));
	move->up = vector_new(0, 1*mod, 0);
	move->down = vector_new(0, -1*mod, 0);
	move->left = vector_new(-1*mod, 0, 0);
	move->right = vector_new(1*mod, 0, 0);
	move->forward = vector_new(0, 0, -1*mod);
	move->backward = vector_new(0, 0, 1*mod);
	move->rotate_x_left = quaternion_new(cosf(0.1308995f), sinf(0.1308995f), 0, 0);
	move->rotate_x_right = quaternion_new(cosf(0.1308995f), -sinf(0.1308995f), 0, 0);
	move->rotate_y_left = quaternion_new(cosf(0.1308995f), 0, sinf(0.1308995f), 0);
	move->rotate_y_right = quaternion_new(cosf(0.1308995f), 0, -sinf(0.1308995f), 0);
	move->rotate_z_left = quaternion_new(cosf(0.1308995f), 0, 0, sinf(0.1308995f));
	move->rotate_z_right = quaternion_new(cosf(0.1308995f), 0, 0, -sinf(0.1308995f));
	data->movement = move;
}

t_quaternion *quaternion_new(float i, float i1, float i2, float i3) {
	t_quaternion *quaternion;

	quaternion = malloc(sizeof(t_quaternion));
	quaternion->w = i;
	quaternion->x = i1;
	quaternion->y = i2;
	quaternion->z = i3;
	return (quaternion);
}

void init_mlx_data(t_data *data) {
	t_mlx_data *mlx_data;

	mlx_data = malloc(sizeof(t_mlx_data));
	mlx_data->mlx = mlx_init();
	mlx_data->win = mlx_new_window(mlx_data->mlx, 800, 600, "miniRT");
	mlx_data->img = mlx_new_image(mlx_data->mlx, 800, 600);
	mlx_data->width = 800;
	mlx_data->height = 600;
	mlx_data->bpp = 32;
	mlx_data->size_line = 800 * 4;
	mlx_data->endian = 0;
	data->mlx_data = mlx_data;

}

void init_checker(t_data *data) {
	data->checker.camera_init = 0;
	data->checker.has_ambient = 0;
	data->checker.has_spot = 0;
	data->checker.has_object = 0;
    data->checker.object_light_toggle = 1;
}

t_light *new_ambient_light(t_data *data) {
	t_light *light;

	light = malloc(sizeof(t_light));
	light->type = 'A';
	if (data->lights == NULL)
		data->lights = light;
	else
		data->lights->next = light;
	light->next = NULL;
	return (light);
}

t_light *new_spot_light(t_data *data) {
	t_light *light;

	light = malloc(sizeof(t_light));
	light->type = 'L';
	if (data->lights == NULL)
		data->lights = light;
	else
		data->lights->next = light;
	light->next = NULL;
	data->checker.has_spot++;
	return (light);
}

t_camera *new_camera(t_data *data) {
	t_camera *camera;

	camera = malloc(sizeof(t_camera));
	camera->next = NULL;
	data->checker.camera_init++;
	return (camera);
}


