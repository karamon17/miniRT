#ifndef MINIRT_PROJECT_CAMERA_H
#define MINIRT_PROJECT_CAMERA_H

#include "miniRT.h"

typedef struct s_camera
{
	t_vector	*origin;
	t_vector	*direction;
	float		fov;
} t_camera;

#endif //MINIRT_PROJECT_CAMERA_H
