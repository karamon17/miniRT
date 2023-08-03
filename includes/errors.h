/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <gkhaishb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:52:50 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/08/03 11:52:51 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "miniRT.h"
# include "camera.h"
# include "figures.h"

# define EXIT_FAILURE	1
# define EXIT_SUCCESS	0

void	wrong_argc(char *program_name);
void	check_camera(t_camera *camera);
void	check_sphere(t_figure *figure);
void	error(const char *string, int i);
void	check_color(t_color color);
void	check_elements(t_data *data);
int		is_outrange_of_float(float number);
void	check_correct_file_extension(char *filename);

#endif
