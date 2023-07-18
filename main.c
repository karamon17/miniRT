#include "miniRT.h"

int main()
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "Hello world!");
	mlx_loop(mlx);
}
