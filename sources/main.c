
#include "../includes/miniRT.h"


int main(int argc, char **argv)
{
    void *mlx;
    void *win;
    t_data *rt_data;

    rt_data = malloc(sizeof(t_data));
    if (argc < 2 || argc > 3)
        wrong_argc(argv[0]);
    rt_data->filename = argv[1];
    parse_rt_file(rt_data);
    mlx = mlx_init();
    win = mlx_new_window(mlx, 1920, 1080, "miniRT");
    mlx_loop(mlx);
    return (0);
}
