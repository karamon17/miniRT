#ifndef MINIRT_PROJECT_CAMERA_H
#define MINIRT_PROJECT_CAMERA_H

#include "miniRT.h"
#include "vector.h"

typedef struct s_camera
{
	t_vector	origin;
	t_vector	direction;
	t_vector 	up_vector;
	t_vector	right_vector;
	float		fov;
	struct s_camera *next;
} t_camera;

#endif //MINIRT_PROJECT_CAMERA_H
