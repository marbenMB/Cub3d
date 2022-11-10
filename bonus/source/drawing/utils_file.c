/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 10:24:50 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/10/24 05:55:12 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

t_distance	get_distance(t_data *data, t_index *ray)
{
	t_distance	distance;
	t_index		player;

	player = player_possition(data, 'Y', 'N');
	distance.wall = best_wall_distance(data, ray, player);
	door_distance(data, player);
	return (distance);
}

void	draw_line(t_data *data, t_index first, t_index last, int color)
{
	double	i;
	double	step;

	i = 0;
	if (fabs(ft_diff(first.x, last.x)) > fabs(ft_diff(first.y, last.y)))
		step = fabs(ft_diff(first.x, last.x));
	else
		step = fabs(ft_diff(first.y, last.y));
	while (i < step)
	{
		if (point_in_circle(data, first.x, first.y))
			ft_put_pixel(first.x, first.y, data, color);
		first.x += ft_diff(first.x, last.x) / step;
		first.y += ft_diff(first.y, last.y) / step;
		i += 0.1;
	}
}

void	check_key(t_data *data)
{
	t_index	step;

	step.x = STEP * cos(data->player.alpha);
	step.y = STEP * sin(data->player.alpha);
	movement_key(data, step);
	if (data->my_hook.key_a == 1)
	{
		if (ft_check_wall(data, -step.x, step.y))
		{
			data->player.player_x = data->player.player_x + step.y;
			data->player.player_y = data->player.player_y - step.x;
		}
	}
	if (data->my_hook.key_east == 1)
	{
		data->player.alpha += ALPHA;
		data->player.alpha = normalizeangle(data->player.alpha);
	}
	if (data->my_hook.key_west == 1)
	{
		data->player.alpha -= ALPHA;
		data->player.alpha = normalizeangle(data->player.alpha);
	}
}

int	ft_mouse_release(int mouse, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (mouse == 1)
	{
		data->mouse.mouse_release = 1;
		data->mouse.mouse_press = 0;
	}
	return (0);
}

int	mouvment_mouse(int x, int y, t_data *data)
{
	(void)y;
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		if (data->mouse.sav_x - x > 0 && data->mouse.mouse_press)
		{
			data->player.alpha -= (ALPHA);
			data->mouse.sav_x = x;
		}
		if (data->mouse.sav_x - x < 0 && data->mouse.mouse_press)
		{
			data->player.alpha += (ALPHA);
			data->mouse.sav_x = x;
		}
		data->player.alpha = normalizeangle(data->player.alpha);
	}
	return (0);
}
