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
void parse_elements(char *file_content, t_data *data);
void parse_element(char *element_line, t_data *data);
void parse_ambient_light(char *line, t_data *data);
float parse_intesity(char *string);
t_color *parse_color(char *string);

//utils
void free_array(char **array);
float ft_atof(char *string);
int array_lenth(char **array);
char *remove_overstricked_space(char *line);

//errors
void error(const char *string, int i);


#endif //MINIRT_PARSER_H
