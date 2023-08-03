/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibX_handler.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <gkhaishb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:52:59 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/08/03 11:53:00 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBX_HANDLER_H
# define MINILIBX_HANDLER_H

# include "miniRT.h"

# define KEY_S	1
# define KEY_D	2
# define KEY_W	13
# define KEY_Q	12
# define KEY_E	14
# define KEY_A	0
# define KEY_Z	6
# define KEY_C	8
# define KEY_R		      15
# define KEY_F            3
# define KEY_ESC 		  53
# define KEY_UP_ARROW     126
# define KEY_DOWN_ARROW   125
# define KEY_LEFT_ARROW   123
# define KEY_RIGHT_ARROW  124
# define KEY_1            83
# define KEY_2            84
# define KEY_3            85
# define KEY_4            86
# define KEY_5            87
# define KEY_6            88
# define KEY_MINUS        78
# define KEY_PLUS         69
# define LEFT_CLICK       1
# define KEY_SPACE        49

void			mlx_hooks_handler(t_data *data);
int				ft_exit(int keycode, void *f);
int				press_keys(int keycode, t_data *data);
int				mouse_handle(int button, int x, int y, t_data *data);
int				press_object_movement_keys(int keycode, t_data *data);
void			press_camera_rotation_keys(int keycode, t_data *data);
int				is_object_movement_key(int keycode);
int				is_camera_movement_key(int keycode);
void			press_camera_movement_keys(int keycode, t_data *data);
int				is_camera_rotation_key(int keycode);
void			get_object(t_data *data, int x, int y);
void			move_object(t_data *data, t_vector direction);
t_quaternion	multiply_quaternion(t_quaternion q1, t_quaternion q2);
t_quaternion	quaternion_new(float i, float i1, float i2, float i3);
void			quaternion_normalize(t_quaternion quaternion);
int				is_object_rotation_key(int keycode);
void			press_object_rotation_keys(int keycode, t_data *data);
void			rotate_object(t_data *data, t_quaternion direction);
t_quaternion	conjugate(t_quaternion q);
void			switch_object_light(int keycode, t_data *data);
void			work_with_object(int keycode, t_data *data);
void			move_light(t_data *data, t_vector direction);
void			move_figure(t_data *data, t_vector direction);
void			move_vector(t_vector *vector,
					t_vector direction, int direction_flag);
void			rotate_quaternion(t_vector *vector, t_quaternion direction);
void			rotate_figure(t_data *data, t_quaternion direction);
void			work_with_camera(int keycode, t_data *data);
void			rotate_camera(t_data *data, t_quaternion direction);
void			rotate_figure_for_camera(t_data *data, t_vector *figure_center,
					t_quaternion direction);
void			move_camera(t_data *data, t_vector direction, int is_positive);
void			move_obj_for_camera(t_vector *figure_center,
					t_vector direction, int is_positive);
void			rotate_light_for_camera(t_data *data, t_quaternion direction);

#endif
