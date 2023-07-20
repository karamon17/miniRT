#ifndef MINIRT_PROJECT_MINIRT_H
#define MINIRT_PROJECT_MINIRT_H

#include "vector.h"
#include "unistd.h"
#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "figures.h"
#include "camera.h"
#include "light.h"
#include "scene.h"
#include "view_plane.h"
#include "mlx.h"
#include "errors.h"
#include "parser.h"
#include "../libft/libft.h"
#include <sys/fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_data
{
    void	*mlx;
    void	*win;
    char    *filename;
	t_scene *scene;
	int 	width;
	int 	height;
	int 	all_init;
	int result_init;
	int camera_init;
	int has_ambient;
	int has_light;
	t_figures *figures;
	t_list *lights;
} t_data;


t_light  *light_new(t_vector *vector, char	type, float	intensity);
float	compute_lighting(t_scene *scene, t_vector *p, t_vector *n);

#endif //MINIRT_PROJECT_MINIRT_H
