#include "../includes/miniRT.h"

void ray_trace(void *mlx, t_data *data)
{
    int mlx_x;
    int mlx_y = 0;
    float x_angle;
    float y_angle;
    float x_ray;
    float y_ray;
    int color;
    t_mlx_data *mlx_data = data->mlx_data;

    mlx_data->img = mlx_new_image(mlx, (int)mlx_data->width, (int)mlx_data->height+1);
    int *img_data = (int *)mlx_get_data_addr(mlx_data->img, &mlx_data->bpp, &mlx_data->size_line, &mlx_data->endian);

    t_vector *ray;
    t_view_plane *vplane;
    vplane = view_plane_new(mlx_data->height, mlx_data->width, data->camera->fov);
    y_angle = mlx_data->height / 2.f;
    while (y_angle >= (mlx_data->height / 2.f) * -1)
    {
        y_ray = y_angle * vplane->y_pixel;
        x_angle = (mlx_data->width / 2.f) * -1;
        mlx_x = 0;
        while (x_angle <= mlx_data->width / 2)
        {
            x_ray = x_angle * vplane->x_pixel;
            ray = vector_new(x_ray, y_ray , data->camera->direction->z);
			ray->x += data->camera->direction->x;
			ray->y += data->camera->direction->y;
            vector_normalize(ray);
            color = get_color(data, ray);
            img_data[mlx_x + mlx_y * (int)mlx_data->width] = color;
            free(ray);
            x_angle++;
            mlx_x++;
        }
        y_angle--;
        mlx_y++;
    }
    free(vplane);
    mlx_put_image_to_window(data->mlx_data->mlx, data->mlx_data->win, data->mlx_data->img, 0, 0);
}

