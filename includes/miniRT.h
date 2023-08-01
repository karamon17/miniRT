#ifndef MINIRT_H
# define MINIRT_H

//parse
# include "errors.h"
# include "parser.h"

//miniLibX
# include "minilibX_handler.h"

//main
# include "vector.h"
# include "figures.h"
# include "camera.h"
# include "light.h"
# include "view_plane.h"

//standard libraries
# include <sys/fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <float.h>
# include <math.h>
# include "mlx.h"
# include "../libft/libft.h"

# define EPSILON 0.001

float		compute_lighting(t_data *data, t_vectors *input, float s);
t_figure	*closest_inters(t_figure *figure, t_vector vector,
				t_vector ray, float *closest_dist);
float		cylinder_intersection(t_vector o, t_vector d, t_figure *cylinder);
float		distance(t_vector *p1, t_vector *p2);
t_vector	*vector_add(t_vector *v1, t_vector *v2);
t_vector	normalize2(t_vector p);
t_figure	*check_intersection(t_figure *figure,
				t_vector vector, t_vector ray);
int			get_color(t_data *data, t_vector ray);
t_color		color_multiply(t_color color, float intecivity);
void		init_camera(t_data *data);
void	ft_newplane(t_figure *new_plane, t_figure *new_plane2, \
t_vector v4, t_figure *cyl);
t_vector *cy_normal, t_figure *cyl);
float	cy_intersection(t_vector o, t_vector d, \

typedef struct s_win_params
{
	int		mlx_x;
	int		mlx_y;
	float	x_angle;
	float	y_angle;
	float	x_ray;
	float	y_ray;

}	t_win_params;

typedef struct s_checker
{
	int	camera_init;
	int	has_ambient;
	int	has_spot;
	int	has_object;
	int	object_light_toggle;

}	t_checker;

typedef struct s_mlx_data
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*img_data;
	float	width;
	float	height;
	int		bpp;
	int		size_line;
	int		endian;
}	t_mlx_data;

typedef struct s_movement
{
	t_vector		up;
	t_vector		down;
	t_vector		left;
	t_vector		right;
	t_vector		forward;
	t_vector		backward;
	t_quaternion	rotate_x_left;
	t_quaternion	rotate_x_right;
	t_quaternion	rotate_y_left;
	t_quaternion	rotate_y_right;

}	t_movement;

typedef struct s_data
{
	char		*filename;
	t_camera	*camera;
	t_figure	*figures;
	t_light		*lights;
	t_checker	checker;
	t_mlx_data	*mlx_data;
	t_movement	*movement;
	t_figure	*closest_figure;
}	t_data;

typedef struct s_abc
{
	float	a;
	float	b;
	float	c;
}	t_abc;

#endif
