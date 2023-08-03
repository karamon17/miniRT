/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_plane.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <gkhaishb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:53:13 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/08/03 11:53:15 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_PLANE_H
# define VIEW_PLANE_H

# include "miniRT.h"

typedef struct s_mlx_data	t_mlx_data;

typedef struct s_view_plane
{
	float	height;
	float	width;
	float	x_pixel;
	float	y_pixel;
	float	fov;
}	t_view_plane;

t_view_plane	*view_plane_new(float height, float width, float fov);
float			sphere_intercept(t_figure *sphere,
					t_vector vector, t_vector ray);
void			ray_trace(t_mlx_data *mlx_data, t_data *data);
float			plane_intercept(t_figure *plane, t_vector vector, t_vector ray);
float			cylinder_intercept(t_figure *cylinder,
					t_vector vector, t_vector ray);

#endif
