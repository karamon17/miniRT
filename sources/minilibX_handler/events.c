#include "../includes/miniRT.h"

void print_coordinats(t_data *pData);

int	press_keys(int keycode, t_data *data)
{
	if(is_object_key(keycode))
		press_object_movement_keys(keycode, data);
	else if(is_camera_movement_key(keycode))
		press_camera_movement_keys(keycode, data);
	else if(is_camera_rotation_key(keycode))
		press_camera_rotation_keys(keycode, data);
	else if (keycode == KEY_ESC)
		exit(0);
    print_coordinats(data);
	ray_trace(data->mlx_data->mlx, data);
	return (0);
}

void print_coordinats(t_data *pData) {
    printf("Camera origin: %f %f %f\n", pData->camera->origin->x, pData->camera->origin->y, pData->camera->origin->z);
    printf("Camera direction: %f %f %f\n", pData->camera->direction->x, pData->camera->direction->y, pData->camera->direction->z);
    //printf("Sphere: %f %f %f\n", pData->figures->figure_body.sphere.center->x, pData->figures->figure_body.sphere.center->y, pData->figures->figure_body.sphere.center->z);
    //printf("light: %f %f %f\n", pData->lights->vector->x, pData->lights->vector->y, pData->lights->vector->z);
}

void	mlx_hooks_handler(t_data *data)
{
	mlx_hook(data->mlx_data->win, 4, 1, mouse_handle, data);
	mlx_hook(data->mlx_data->win, 2, 1, press_keys, data);
	mlx_hook(data->mlx_data->win, 17, 1L << 2, ft_exit, (void *)0);
	mlx_loop(data->mlx_data->mlx);
}
