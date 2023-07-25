#ifndef MINIRT_MINILIBX_HANDLER_H
#define MINIRT_MINILIBX_HANDLER_H

#include "miniRT.h"

# define KEY_S		1
# define KEY_D		2
# define KEY_W		13
# define KEY_Q		12
# define KEY_E		14
# define KEY_A		0
# define KEY_ESC	53
#define KEY_UP_ARROW     126
#define KEY_DOWN_ARROW   125
#define KEY_LEFT_ARROW   123
#define KEY_RIGHT_ARROW  124

#define KEY_0            82
#define KEY_1            83
#define KEY_2            84
#define KEY_3            85
#define KEY_4            86
#define KEY_5            87
#define KEY_6            88
#define KEY_7            89
#define KEY_8            91
#define KEY_9            92


void	mlx_hooks_handler(t_data *data);
int	ft_exit(int keycode, void *f);
int	press_keys(int keycode, t_data *data);
int	mouse_whilling(int button, int x, int y, t_data *data);
int	press_object_movement_keys(int keycode, t_data *data);
void press_camera_rotation_keys(int keycode, t_data *data);
int is_object_key(int keycode);
int is_camera_movement_key(int keycode);
void press_camera_movement_keys(int keycode, t_data *data);
int is_camera_rotation_key(int keycode);


void move_cam_forward(t_data *data);
void move_cam_backward(t_data *data);
void move_cam_up(t_data *data);
void move_cam_down(t_data *data);
void move_cam_left(t_data *data);
void move_cam_right(t_data *data);

#endif //MINIRT_MINILIBX_HANDLER_H
