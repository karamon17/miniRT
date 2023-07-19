#include "../includes/miniRT.h"

int main()
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 1920, 1080, "miniRT");
    mlx_loop(mlx);
    return (0);
}
