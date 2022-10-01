/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:04:54 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/10/01 18:33:44 by mbenbajj         ###   ########.fr       */
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
			else if (ft_strchr("NEWS0",data->map[y][x]))
				draw_2d_cube(data, x, y, WHITE);
			x++;
		}
		y++;
	}
	draw_2d_player(data, RED);
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

void	draw_2d_player(t_data *data, int color)
{
	if (check_isWall(data))
	{
		data->play->x_player += data->play->x_move;
		data->play->y_player += data->play->y_move;
	}
	casting(data, color);
	// ft_mlx_pixel_put(data, data->play->x_player , data->play->y_player , color);
	data->play->x_move = 0;
	data->play->y_move = 0;
}

void	draw_2d_line(t_data *data, double x2, double y2, int color)
{
	double	dx;
	double	dy;
	double	steps;
	double	xinc;
	double	yinc;

	dx = data->play->x_player - x2;
	dy = data->play->y_player - y2;
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
		ft_mlx_pixel_put(data, round(data->play->x_player + xinc * i), round(data->play->y_player + yinc * i), color);
		i++;
	}
}