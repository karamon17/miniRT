
#include "../includes/miniRT.h"


t_data *init_data(char *input);

void print_camera_content(t_camera *pCamera);

void print_light_content(t_light *pLight);

void print_figures_content(t_figure *pFigures);

void print_sphere_content(t_figure *pFigures);

int main(int argc, char **argv)
{
    //void *mlx;
    //void *win;
    t_data *data;

    if (argc < 2 || argc > 3)
		wrong_argc(argv[0]);
	data = init_data(argv[1]);
    parse_rt_file(data);
    //mlx = mlx_init();
    /*win = mlx_new_window(mlx, 1920, 1080, "miniRT");
    mlx_loop(mlx);
    */
	print_camera_content(data->scene->camera);
	print_light_content(data->lights);
	print_figures_content(data->figures);
	return (0);
}

void print_figures_content(t_figure *pFigures) {
	if(pFigures == NULL)
		printf("No figures\n");

	t_figure *tmp = pFigures;

	while(tmp) {
		if (tmp->type == SPHERE)
			print_sphere_content(tmp);
		/*else if(pFigures->type == 'p')
			printf("Plane:\n");
		else if(pFigures->type == 'c')
			printf("Cylinder:\n");
		else if(pFigures->type == 't')
			printf("Triangle:\n");
		else if(pFigures->type == 's')
			printf("Square:\n");
		else
			printf("Unknown figure\n");*/
		tmp = tmp->next;
	}
}

void print_sphere_content(t_figure *pFigures) {
	printf("Sphere:\n");
	printf("Position: %f %f %f\n", pFigures->figure_body.sphere.center->x, pFigures->figure_body.sphere.center->y, pFigures->figure_body.sphere.center->z);
	printf("radius: %f\n", pFigures->figure_body.sphere.radius);
	printf("Color: %f %f %f\n", pFigures->figure_body.sphere.RGB_color->red, pFigures->figure_body.sphere.RGB_color->green, pFigures->figure_body.sphere.RGB_color->blue);
}

void print_light_content(t_light *pLight) {

	while(pLight)
	{
		printf("Light:\n");
		printf("Type: %c\n", pLight->type);
		if(pLight->type != 'A')
			printf("Position: %f %f %f\n", pLight->vector->x, pLight->vector->y, pLight->vector->z);
		printf("Intensity: %f\n", pLight->intensity);
		printf("Color: %f %f %f\n", pLight->RGB_color->red, pLight->RGB_color->green, pLight->RGB_color->blue);
		pLight = pLight->next;
	}
}

void print_camera_content(t_camera *pCamera) {
	printf("Camera:\n");
	printf("Position: %f %f %f\n", pCamera->origin->x, pCamera->origin->y, pCamera->origin->z);
	printf("Orientation: %f %f %f\n", pCamera->direction->x, pCamera->direction->y, pCamera->direction->z);
	printf("FOV: %f\n", pCamera->fov);
}
