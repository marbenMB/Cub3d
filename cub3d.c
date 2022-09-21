/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:07:09 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/09/19 20:00:54 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_data *data)
{
	data->map_height = 0;
	data->map_width = 0;
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		printf("\x1b[31m Error in arguments \033[0m\n");
		return (1);
	}
	else
    {
        init_data(&data);
		get_parced_map(&data, av[1]);
    }
	
	int	x = 0;
	int	y = 0;
	while (data.map[x])
	{
		y = 0;
		while (data.map[x][y])
		{
			printf("%c", data.map[x][y]);
			y++;
		}
		x++;
	}
	// drawing(&data);
	return (0);
}