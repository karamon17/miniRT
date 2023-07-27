#include "../includes/miniRT.h"

void ray_trace(void *mlx, t_data *data)
{
    t_win_params w_params;
    t_vector *ray;
    t_view_plane *vplane;
    int color;

    t_mlx_data *mlx_data = data->mlx_data;
    mlx_data->img = mlx_new_image(mlx, (int)mlx_data->width, (int)mlx_data->height+1);
    mlx_data->img_data = (int *)mlx_get_data_addr(mlx_data->img, &mlx_data->bpp, &mlx_data->size_line, &mlx_data->endian);
    w_params.mlx_y = 0;
    vplane = view_plane_new(mlx_data->height, mlx_data->width, data->camera->fov);
    w_params.y_angle = mlx_data->height / 2.f;
    while (w_params.y_angle >= (mlx_data->height / 2.f) * -1)
    {
        w_params.y_ray = w_params.y_angle * vplane->y_pixel;
        w_params.x_angle = (mlx_data->width / 2.f) * -1;
        w_params.mlx_x = 0;
        while (w_params.x_angle <= mlx_data->width / 2)
        {
            w_params.x_ray = w_params.x_angle * vplane->x_pixel;
            ray = vector_new(w_params.x_ray, w_params.y_ray , data->camera->direction->z);
			ray->x += data->camera->direction->x;
			ray->y += data->camera->direction->y;
            vector_normalize(ray);
            color = get_color(data, ray);
            mlx_data->img_data[w_params.mlx_x + w_params.mlx_y * (int)mlx_data->width] = color;
            free(ray);
            w_params.x_angle++;
            w_params.mlx_x++;
        }
        w_params.y_angle--;
        w_params.mlx_y++;
    }
    free(vplane);
    mlx_put_image_to_window(data->mlx_data->mlx, data->mlx_data->win, data->mlx_data->img, 0, 0);
}













// float	cylinder_intercept(t_figure *cylinder, t_vector *vector, t_vector *ray)
// {
// 	t_vector *oc;
// 	t_vector *center = cylinder->figure_body.cylinder.center;
// 	t_vector *normal = cylinder->figure_body.cylinder.normal;
// 	float	radius_sq = cylinder->figure_body.cylinder.radius;
// 	radius_sq *= radius_sq;
// 	float height = cylinder->figure_body.cylinder.height;

// 	oc = vector_subtract(vector, center);

// 	float proj_x = ray->x - ray->z * normal->x;
//     float proj_y = ray->y - ray->z * normal->y;

//     float a = ray->x * ray->x + ray->y * ray->y - ray->z * ray->z;
//     float b = 2 * (ray->x * oc->x + ray->y * oc->y - ray->z * oc->z);
//     float c = oc->x * oc->x + oc->y * oc->y - oc->z * oc->z - radius_sq;

//     float discriminant = b * b - 4 * a * c;

//     float t1, t2, t_bottom, t_top;

//     // Проверяем пересечение с боковой поверхностью цилиндра
//     if (discriminant >= 0)
// 	{
//         t1 = (-b + sqrtf(discriminant)) / (2 * a);
//         t2 = (-b - sqrtf(discriminant)) / (2 * a);
//         // Проверяем, лежат ли точки пересечения на высоте цилиндра
//         float z1 = vector->z + t1 * ray->z;
//         float z2 = vector->z + t2 * ray->z;
//         if (z1 >= center->z && z1 <= center->z + height) {
//             return t1;
//         } else if (z2 >= center->z && z2 <= center->z + height) {
//             return t2;
//         }
//     }
//     // Проверяем пересечение с плоскостью основания цилиндра
//     t_bottom = ((center->z - vector->z) / ray->z) / (normal->z - proj_x * normal->x - proj_y * normal->y);
//     t_top = ((center->z + height - vector->z) / ray->z) / (normal->z - proj_x * normal->x - proj_y * normal->y);

//     // Проверяем, лежат ли точки пересечения с плоскостью основания внутри круга с радиусом cylinder->radius
//     float x_bottom = vector->x + t_bottom * ray->x - (center->x + t_bottom * proj_x);
//     float y_bottom = vector->y + t_bottom * ray->y - (center->y + t_bottom * proj_y);
//     if (x_bottom * x_bottom + y_bottom * y_bottom <= radius_sq) {
//         return t_bottom;
//     }
//     float x_top = vector->x + t_top * ray->x - (center->x + t_top * proj_x);
//     float y_top = vector->y + t_top * ray->y - (center->y + t_top * proj_y);
//     if (x_top * x_top + y_top * y_top <= radius_sq) {
//         return t_top;
//     }
//     return 0;
// }

