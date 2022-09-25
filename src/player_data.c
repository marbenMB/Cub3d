/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:06:17 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/09/24 18:21:06 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_player_data(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (ft_strchr("NEWS",data->map[y][x]))
			{
				data->x_player = x;
				data->y_player = y;
				init_angle(data, data->map[y][x]);
				break ;
			}
			x++;
		}
		y++;
	}
}

void    init_angle(t_data *data, char player)
{
	if (player == 'N')
		data->view_angle = M_PI / 2;
	else if (player == 'S')
		data->view_angle = 3 * M_PI / 2;
	else if (player == 'W')
		data->view_angle = M_PI;
	else if (player == 'E')
		data->view_angle = 0;
}