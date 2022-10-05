/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:15:32 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/10/05 21:44:45 by mbenbajj         ###   ########.fr       */
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
	int			check;

	st_inter.dy = floor(data->play->y_player / TILE_SIZE) * TILE_SIZE;
	if (data->rays->face.down)
		st_inter.dy += TILE_SIZE;
	st_inter.dx = data->play->x_player - (data->play->y_player - st_inter.dy) / tan(data->rays->angle);
	
	step.dy = TILE_SIZE;
	check = 0;
	if (data->rays->face.up)
	{
		step.dy *= -1;
		check = 1;
	}
	step.dx = TILE_SIZE / tan(data->rays->angle);
	if (data->rays->face.left && step.dx > 0)
		step.dx *= -1;
	if (data->rays->face.right && step.dx < 0)
		step.dx *= -1;
	// if (data->rays->face.left && data->rays->face.down)
	// 	step.dx *= -1;
	while (!check_rayWall(data, st_inter.dx, st_inter.dy - check))
	{
		st_inter.dy += step.dy;
		st_inter.dx += step.dx;
	}
	data->rays->distance = sqrtf(st_inter.dx + data->play->x_player) + sqrtf(st_inter.dy + data->play->y_player);
	if (check_rayWall(data, st_inter.dx, st_inter.dy - check) != -1)
		draw_2d_line(data, st_inter.dx, st_inter.dy, GREY);
}
