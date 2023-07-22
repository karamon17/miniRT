#ifndef MINIRT_MINILIBX_HANDLER_H
#define MINIRT_MINILIBX_HANDLER_H

#include "miniRT.h"

void	mlx_hooks_handler(t_data *data);
int	ft_exit(int keycode, void *f);
int	press_exit(int keycode, void *f);
int	mouse_whilling(int button, int x, int y, t_data *data);
int	press_object_movement_keys(int keycode, t_data *data);


#endif //MINIRT_MINILIBX_HANDLER_H
