/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <gkhaishb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:52:46 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/08/03 11:52:48 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "miniRT.h"
# include "vector.h"

typedef struct s_camera
{
	t_vector		origin;
	t_vector		direction;
	t_vector		up_vector;
	t_vector		right_vector;
	float			fov;
	struct s_camera	*next;
}				t_camera;

#endif
