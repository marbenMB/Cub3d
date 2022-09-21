/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:04:54 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/09/21 18:32:22 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img->addr + (y * data->img->line_length + x * (data->img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	drawing(t_data *data)
{
	draw_2d(data);
}

void	draw_2d(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 1)
				draw_2d_wall(data, x, y);
			x++;
		}
		y++;
	}
}

void	draw_2d_wall(t_data *data, int x, int y)
{
	int		xdx;
	int		ydx;

	ydx = y;
	while (ydx <= y + 32)
	{
		xdx = x;
		while (xdx <= x + 32)
		{
			ft_mlx_pixel_put(data, xdx, ydx, 'R');
			xdx++;
		}
		ydx++;
	}
}