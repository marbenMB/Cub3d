/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:15:32 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/10/04 17:49:14 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	casting(t_data *data)
{
	int		id;

	id = 0;
	data->rays->angle = data->play->view_angle - (FOV / 2);
	while (id <= NUM_RAYS)
	{
		normilize_angle(&data->rays->angle);
		init_rayData(data);
		break;
		data->rays->angle += VAR_ANG;
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

	st_inter.dy = floor(data->play->y_player / TILE_SIZE) * TILE_SIZE;
	st_inter.dx = data->play->x_player + (data->play->y_player - st_inter.dy) / tan(data->rays->angle);
	step.dx = st_inter.dx;
	step.dy = st_inter.dy;
	while (check_isWall(data, step.dx, step.dy))
	{
		step.dy = TILE_SIZE;
		step.dx = TILE_SIZE / tan(data->rays->angle);
		st_inter.dy += step.dy;
		st_inter.dx += step.dx;
	}
	data->rays->distance = sqrtf(data->play->x_player - st_inter.dx) + sqrtf(data->play->y_player - st_inter.dy);
	draw_2d_line(data, st_inter.dx, st_inter.dy, GREY);
}
