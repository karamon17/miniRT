#include "../../includes/miniRT.h"

void init_checker(t_data *data);

t_data *init_data(char *input) {

	t_data *rt_data;

	rt_data = malloc(sizeof(t_data));
	rt_data->filename = input;
	rt_data->scene = malloc(sizeof(t_scene));
	rt_data->lights = NULL;
	rt_data->figures = NULL;
	init_checker(rt_data);
	return (rt_data);
}

void init_checker(t_data *data) {
	data->checker.camera_init = 0;
	data->checker.has_ambient = 0;
	data->checker.has_light = 0;
	data->checker.has_object = 0;

}

t_light *new_ambient_light(t_data *data) {
	t_light *light;

	light = malloc(sizeof(t_light));
	light->type = 'A';
	if(data->checker.has_light == 0)
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
	if (data->checker.has_light == 0)
		data->lights = light;
	else
		data->lights->next = light;
	light->next = NULL;
	data->checker.has_light++;
	return (light);
}

t_camera *new_camera(t_data *data) {
	t_camera *camera;

	camera = malloc(sizeof(t_camera));
	camera->next = NULL;
	data->checker.camera_init++;
	return (camera);
}


