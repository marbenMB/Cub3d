/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:15:32 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/10/03 18:42:00 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	casting(t_data *data)
{
	int		id;

	id = 0;
	data->rays->angle = data->play->view_angle - (FOV / 2);
	normilize_angle(&data->rays->angle);
	while (id <= NUM_RAYS)
	{
		data->rays->angle += VAR_ANG;
		init_rayData(data);
		draw_2d_line(data, data->play->x_player + (cos(data->rays->angle) * LINE_LEN), data->play->y_player + (sin(data->rays->angle) * LINE_LEN), GREY);
		id++;
	}
}

void	init_rayData(t_data *data)
{
	check_playFace(data->rays);
	horizontal_inter(data);
}

void	horizontal_inter(t_data *data)
{
	t_index		st_inter;
	t_index		step;

	st_inter.dy = floorf(data->play->y_player / TILE_SIZE) * TILE_SIZE;
	st_inter.dx = data->play->x_player + (data->play->y_player - st_inter.dy) / tan(data->rays->angle);
	step.dx = 0;
	step.dy = 0;
	while (check_isWall(data, step.dx, step.dy))
	{
		step.dy = TILE_SIZE;
		step.dy = TILE_SIZE / tan(data->rays->angle);
		st_inter.dy += step.dy;
		st_inter.dx += step.dx;
	}
}
