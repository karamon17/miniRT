#include "../../includes/miniRT.h"

void print_figures_content(t_figure *pFigures) {
	if(pFigures == NULL)
		printf("No figures\n");

	t_figure *tmp = pFigures;

	while(tmp) {
		if (tmp->type == SPHERE)
			print_sphere_content(tmp);
		if(tmp->type == PLANE)
			print_plane_content(tmp);
		/*else if(pFigures->type == 'c')
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

void print_plane_content(t_figure *pFigures) {
	printf("Plane:\n");
	printf("Position: %f %f %f\n", pFigures->center->x, pFigures->center->y, pFigures->center->z);
	printf("Normal: %f %f %f\n", pFigures->body.plane.normal->x, pFigures->body.plane.normal->y, pFigures->body.plane.normal->z);
	printf("Color: %f %f %f %f\n", pFigures->RGB_color->red, pFigures->RGB_color->green, pFigures->RGB_color->blue, pFigures->RGB_color->transparency);

}

void print_sphere_content(t_figure *pFigures) {
	printf("Sphere:\n");
	printf("Position: %f %f %f\n", pFigures->center->x, pFigures->center->y, pFigures->center->z);
	printf("radius: %f\n", pFigures->body.sphere.rad);
	printf("Color: %f %f %f %f\n", pFigures->RGB_color->red, pFigures->RGB_color->green, pFigures->RGB_color->blue, pFigures->RGB_color->transparency);
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

void print_coordinats(t_data *pData) {
	printf("Camera origin: %f %f %f\n", pData->camera->origin->x, pData->camera->origin->y, pData->camera->origin->z);
	printf("Camera direction: %f %f %f\n", pData->camera->direction->x, pData->camera->direction->y, pData->camera->direction->z);
	//printf("Sphere: %f %f %f\n", pData->figures->body.sphere.center->x, pData->figures->body.sphere.center->y, pData->figures->body.sphere.center->z);
	//printf("light: %f %f %f\n", pData->lights->vector->x, pData->lights->vector->y, pData->lights->vector->z);
}
