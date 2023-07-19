#include "../includes/miniRT.h"

t_camera  *camera_new(t_vector *origin, t_vector *direction, float fov)
{
	t_camera	*camera;

	camera = malloc(sizeof(t_camera));
	if (!camera)
		return (NULL);
	camera->origin = origin;
	camera->direction = direction;
	camera->fov = fov;
	return (camera);
}
