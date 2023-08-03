/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <gkhaishb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:53:05 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/08/03 11:53:06 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "miniRT.h"

# define BUFFER_SIZE 100

typedef struct s_data	t_data;

char		*read_file(char *str, int fd);
void		parse_rt_file(t_data *data);
void		parse_elements(char *file_content, t_data *data);
void		parse_element(char *element_line, t_data *data);
void		parse_ambient_light(char *line, t_data *data);
float		parse_intesity(char *string);
t_color		parse_color(char *string);
void		parse_camera(char *line, t_data *data);
t_vector	parse_vector(char *string);
t_camera	*new_camera(t_data *data);
void		parse_spot_light(char *line, t_data *data);
void		parse_sphere(char *line, t_data *data);
void		parse_plane(char *line, t_data *data);
void		parse_cylinder(char *line, t_data *data);
//init
t_light		*new_spot_light(t_data *data);
t_figure	*add_figure(t_data *data, int type, float specular);
void		init_checker(t_data *data);
t_data		*init_data(char *input);
void		check_plane(t_figure *figure);
void		check_cylinder(t_figure *figure);
void		init_mlx_data(t_data *data);
void		init_move_data(t_data *data);

//utils
void		free_array(char **array);
float		ft_atof(char *string);
int			array_lenth(char **array);
char		*remove_overstricked_space(char *line);
int			ft_strisdigit(char *string);
int			is_normalized(t_vector *vector);
void		add_to_list(t_figure *figures_list, t_figure *figure);
void		adjast_camera(t_data *data, t_vector camera_position);
void		do_atof(char *string, int *i, float *result, float *power);

#endif
