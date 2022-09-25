/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:04:54 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/09/25 15:09:16 by mbenbajj         ###   ########.fr       */
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
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
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
			if (data->map[y][x] == '1')
				draw_2d_cube(data, x, y, RED);
			else if (data->map[y][x] == '0')
				draw_2d_cube(data, x, y, WHITE);
			else if (ft_strchr("NEWS",data->map[y][x]))
			{
				data->x_player = x;
				data->y_player = y;
				draw_2d_cube(data, x, y, WHITE);
			}
			x++;
		}
		y++;
	}
	draw_2d_player(data, data->x_player, data->y_player, RED);
}

void	draw_2d_cube(t_data *data, int x, int y, int color)
{
	int		xdx;
	int		ydx;

	ydx = y * TILE_SIZE;
	while (ydx <= y * TILE_SIZE + TILE_SIZE)
	{
		xdx = x * TILE_SIZE;
		while (xdx <= x * TILE_SIZE + TILE_SIZE)
		{
			ft_mlx_pixel_put(data, xdx, ydx, color);
			xdx++;
		}
		ydx++;
	}
}

void	draw_2d_player(t_data *data, int x, int y, int color)
{
	int		xdx;
	int		ydx;

	ydx = y * TILE_SIZE + TILE_SIZE / 2;
	xdx = x * TILE_SIZE + TILE_SIZE / 2;
	data->x_player = (double)xdx  + data->x_move;
	data->y_player = (double)ydx  + data->y_move;
	draw_2d_line(data, data->x_player + (cos(data->view_angle) * LINE_LEN), data->y_player + sin(data->view_angle) * LINE_LEN, BLACK);
	ft_mlx_pixel_put(data, data->x_player , data->y_player , color);
}

void	draw_2d_line(t_data *data, double x2, double y2, int color)
{
	double	dx;
	double	dy;
	double	steps;
	double	xinc;
	double	yinc;

	dx = data->x_player - x2;
	dy = data->y_player - y2;
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	xinc = dx / steps;
	yinc = dy /steps;
	
	//	drawing
	double	i;
	i = 0;
	while (i <= steps)
	{
		ft_mlx_pixel_put(data, round(data->x_player + xinc * i), round(data->y_player + yinc * i), color);
		i++;
	}
}