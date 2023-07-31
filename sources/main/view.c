#include "../includes/miniRT.h"

t_view_plane *view_plane_new(float height, float width, float fov)
{
    t_view_plane	*view_plane;
    float 			aspect_ratio;

    view_plane = malloc(sizeof(t_view_plane));
    if (!view_plane)
        return (NULL);
    aspect_ratio = width / height;
    view_plane->width = tan(fov / 2 * M_PI / 180) * 2;
    view_plane->height = view_plane->width / aspect_ratio;
    view_plane->x_pixel = view_plane->width / width;
    view_plane->y_pixel = view_plane->height / height;
    return (view_plane);
}