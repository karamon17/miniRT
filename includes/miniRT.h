#ifndef MINIRT_PROJECT_MINIRT_H
#define MINIRT_PROJECT_MINIRT_H

//parse
#include "errors.h"
#include "parser.h"

//miniLibX
#include "minilibX_handler.h"

//main
#include "vector.h"
#include "figures.h"
#include "camera.h"
#include "light.h"
#include "view_plane.h"

//standard libraries
#include <sys/fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <float.h>
#include <math.h>
#include "mlx.h"
#include "../libft/libft.h"

//to remove
#include "to_remove.h"
t_light  *light_new(t_vector *vector, char	type, float	intensity);
float	compute_lighting(t_data *data, t_vector *p, t_vector *n, t_vector *ray, float s);
t_figure * ClosestIntersection(t_figure *figure, t_vector *vector, t_vector *ray, float *closest_dist, t_color **color);
t_figure * check_intersection(t_figure *figure, t_vector *vector, t_vector *ray);

typedef struct s_checker
{
	int camera_init;
	int has_ambient;
	int has_spot;
	int has_object;

} t_checker;

typedef struct s_data
{
    void	*mlx;
    void	*win;
    char    *filename;
	int 	width;
	int 	height;
	t_camera *camera;
	t_figure *figures;
	t_light *lights;
	t_checker checker;
} t_data;




t_light  *light_new(t_vector *vector, char	type, float	intensity);

#endif //MINIRT_PROJECT_MINIRT_H
