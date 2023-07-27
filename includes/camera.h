#ifndef MINIRT_PROJECT_CAMERA_H
#define MINIRT_PROJECT_CAMERA_H

#include "miniRT.h"
#include "vector.h"

typedef struct s_camera
{
	t_vector	*origin;
	t_vector	*direction;
	float		fov;
	struct s_camera *next;
} t_camera;

#endif //MINIRT_PROJECT_CAMERA_H
