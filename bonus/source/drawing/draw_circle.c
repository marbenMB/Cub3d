/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 11:28:52 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/10/23 12:57:29 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

int	point_in_circle(t_data *data, double y, double x)
{
	double	distance;
	t_index	player;
	t_index	point;

	point.x = x;
	point.y = y;
	player = player_possition(data, 'Y', 'Y');
	distance = distance_2_point(player, point);
	if (distance <= RAY)
		return (1);
	return (0);
}

void	get_player_possition(t_data *data)
{
	t_index_int	index;
	t_index		player;

	index.x = 0;
	while (data->map[index.x])
	{
		index.y = 0;
		while (data->map[index.x][index.y])
		{
			if (char_in_str(PLAYER, data->map[index.x][index.y]))
			{
				data->player.face = data->map[index.x][index.y];
				data->player.init_x_player = index.x + 0.5;
				data->player.init_y_player = index.y + 0.5;
				break ;
			}
			index.y++;
		}
		index.x++;
	}
	player = player_possition(data, 'Y', 'N');
	data->player.mouve.x = (RAY + 5) - player.x;
	data->player.mouve.y = (RAY + 5) - player.y;
}

int	ft_close_x(t_data *data)
{
	mlx_destroy_window(data->img->mlx, data->img->win);
	exit(0);
	return (0);
}

t_index	add_step(t_index inter, t_index step)
{
	inter.x += step.x;
	inter.y += step.y;
	return (inter);
}

void	ft_free_list(t_data *data)
{
	t_door	*tmp;

	while (data->lst_door)
	{
		tmp = data->lst_door;
		data->lst_door = data->lst_door->next;
		free(tmp);
	}
}
