#ifndef MINIRT_ERRORS_H
#define MINIRT_ERRORS_H

#include "miniRT.h"

#define	EXIT_FAILURE	1
#define	EXIT_SUCCESS	0

void		wrong_argc(char *program_name);
void fatal();

void check_camera(t_camera *camera);
void check_sphere(t_figure *figure);
void error(const char *string, int i);

#endif //MINIRT_ERRORS_H
