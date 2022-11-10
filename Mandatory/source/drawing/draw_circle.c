/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 11:28:52 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/10/18 09:24:58 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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

double	distance_2_point(t_index first, t_index last)
{
	return (sqrt (pow((last.x - first.x), 2) + pow((last.y - first.y), 2)));
}

void	draw_to_img(t_data *data)
{
	t_img	*img;

	img = data->img;
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bit_img, \
	&img->d_size, &img->endian);
	get_player_possition(data);
	draw_3d(data);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}

double	ft_diff(double x, double y)
{
	return (y - x);
}
