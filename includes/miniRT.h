#ifndef MINIRT_PROJECT_MINIRT_H
#define MINIRT_PROJECT_MINIRT_H

#include "vector.h"
#include "unistd.h"
#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "sphere.h"
#include "camera.h"
#include "scene.h"
#include "view_plane.h"
#include "mlx.h"
#include "errors.h"
#include "parser.h"
#include "../libft/libft.h"
#include <sys/fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_data
{
    void	*mlx;
    void	*win;
    char    *filename;

} t_data;



#endif //MINIRT_PROJECT_MINIRT_H
