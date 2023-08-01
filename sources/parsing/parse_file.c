/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:00:59 by vbudilov          #+#    #+#             */
/*   Updated: 2023/08/01 14:01:01 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	parse_rt_file(t_data *data)
{
	int		fd;
	char	*file_content;

	check_correct_file_extension(data->filename);
	(fd = open(data->filename, 0));
	if ((fd) == -1)
		error("file does not exist\n", EXIT_FAILURE);
	file_content = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	file_content[0] = '\0';
	file_content = read_file(file_content, fd);
	parse_elements(file_content, data);
}

char	*read_file(char *str, int fd)
{
	char	buf[BUFFER_SIZE + 1];
	int		retairment;

	retairment = read(fd, buf, BUFFER_SIZE);
	while (retairment > 0)
	{
		buf[retairment] = '\0';
		str = ft_strjoin(str, buf);
		if (!str)
			error("Error in ft_strjoin\n", EXIT_FAILURE);
		retairment = read(fd, buf, BUFFER_SIZE);
	}
	return (str);
}
