#include "../includes/miniRT.h"

void ray_trace(t_mlx_data *mlx_data, t_data *data)
{
    t_win_params 	w_params;
    t_vector 		ray;
    t_view_plane 	*vplane;
    int 			color;

    mlx_data->img = mlx_new_image(mlx_data->mlx, (int)mlx_data->width, (int)mlx_data->height);
    mlx_data->img_data = (int *)mlx_get_data_addr(mlx_data->img, &mlx_data->bpp, &mlx_data->size_line, &mlx_data->endian);
    w_params.mlx_y = 0;
    vplane = view_plane_new(mlx_data->height, mlx_data->width, data->camera->fov);
    w_params.y_angle = mlx_data->height / 2.f;
    while (w_params.y_angle > (mlx_data->height / 2.f) * -1)
    {
        w_params.y_ray = w_params.y_angle * vplane->y_pixel;
        w_params.x_angle = (mlx_data->width / 2.f) * -1;
        w_params.mlx_x = 0;
        while (w_params.x_angle < mlx_data->width / 2)
        {
            w_params.x_ray = w_params.x_angle * vplane->x_pixel;
            ray = vector_new2(w_params.x_ray, w_params.y_ray, -1);
            vector_normalize(ray);
            color = get_color(data, ray);
            mlx_data->img_data[w_params.mlx_x + w_params.mlx_y * (int)mlx_data->width] = color;
            w_params.x_angle++;
            w_params.mlx_x++;
        }
        w_params.y_angle--;
        w_params.mlx_y++;
    }
    free(vplane);
    mlx_put_image_to_window(data->mlx_data->mlx, data->mlx_data->win, data->mlx_data->img, 0, 0);
}

