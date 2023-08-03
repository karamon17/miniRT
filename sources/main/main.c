/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <gkhaishb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:16:25 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/08/03 15:45:20 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		wrong_argc(argv[0]);
	data = init_data(argv[1]);
	parse_rt_file(data);
	init_camera(data);
	ray_trace(data->mlx_data, data);
	mlx_hooks_handler(data);
	return (0);
}
