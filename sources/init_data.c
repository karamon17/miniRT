#include "../includes/miniRT.h"

t_data *init_data(char *input) {

	t_data *rt_data;

	rt_data = malloc(sizeof(t_data));
	rt_data->filename = input;
	rt_data->scene = malloc(sizeof(t_scene));
	rt_data->lights = NULL;
	rt_data->figures = NULL;
	rt_data->result_init = 0;
	rt_data->all_init = 0;
	rt_data->camera_init = 0;
	rt_data->has_light = 0;
	rt_data->has_ambient = 0;
	return (rt_data);
}

t_light *new_amient_light(t_data *data) {
	t_light *light;

	light = malloc(sizeof(t_light));
	light->type = 'A';
	if(data->has_light == 0)
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
	if (data->has_light == 0)
		data->lights = light;
	else
		data->lights->next = light;
	light->next = NULL;
	data->has_light++;
	return (light);
}

t_camera *new_camera(t_data *data) {
	t_camera *camera;

	camera = malloc(sizeof(t_camera));
	camera->next = NULL;
	data->camera_init++;
	return (camera);
}


