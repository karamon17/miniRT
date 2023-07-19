#ifndef MINIRT_PARSER_H
#define MINIRT_PARSER_H

#include "miniRT.h"

#define BUFFER_SIZE 100

typedef struct s_data t_data;
typedef enum s_object_type
{
    SP,
    PL,
    SQ,
    TR,
    CY,
    CU,
    PY

} t_object_type;

char		*read_file(char *str, int fd);
void parse_rt_file(t_data *data);

#endif //MINIRT_PARSER_H
