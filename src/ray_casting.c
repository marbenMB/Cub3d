/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:15:32 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/10/21 05:19:55 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	casting(t_data *data)
{
	data->rays->id = 0;;
	data->rays->angle = data->play->view_angle - (FOV / 2);
	while (data->rays->id <= NUM_RAYS)
	{
		normilize_angle(&data->rays->angle);
		data->rays->if_is_door = false;
		data->rays->door_inter.var = -1;
		data->rays->where_D = 0;
		init_rayData(data);
		data->rays->angle += VAR_ANG;
		data->rays->id++;
	}
}

void	init_rayData(t_data *data)
{
	check_playFace(data->rays);
	horizontal_inter(data);
	vertical_inter(data);
	rendering_wall(data);
	if (data->rays->if_is_door)
	{
		rendering_door(data);
	}
}

void	horizontal_inter(t_data *data)
{
	t_index		st_inter;
	t_index		step;
	int			check;

	st_inter.dy = floor(data->play->player.dy / TILE_SIZE) * TILE_SIZE;
	if (data->rays->face.down)
		st_inter.dy += TILE_SIZE;
	st_inter.dx = data->play->player.dx + (st_inter.dy - data->play->player.dy) / tan(data->rays->angle);
	step.dy = TILE_SIZE;
	check = 0;
	if (data->rays->face.up)
	{
		step.dy *= -1;
		check = 1;
	}
	step.dx = step.dy / tan(data->rays->angle);
	if (data->rays->face.left && step.dx > 0)
		step.dx *= -1;
	if (data->rays->face.right && step.dx < 0)
		step.dx *= -1;
	while (!check_rayWall(data, st_inter.dx, st_inter.dy - check))
	{
		if (check_rayDoor(data, st_inter.dx, st_inter.dy - check) && !data->rays->if_is_door)
		{
			printf("%d  :  ", data->rays->where_D);
			puts("H");
			data->rays->if_is_door = true;
			data->rays->door_inter.dx = st_inter.dx;
			data->rays->door_inter.dy = st_inter.dy;
			data->rays->door_inter.var = sqrt(pow((st_inter.dx - data->play->player.dx), 2) + pow((st_inter.dy - data->play->player.dy), 2));
			data->rays->where_D = HOR_INTER;
		}
		st_inter.dy += step.dy;
		st_inter.dx += step.dx;
	}
	data->rays->distance = sqrtf(pow((st_inter.dx - data->play->player.dx), 2) + pow((st_inter.dy - data->play->player.dy), 2));
	data->rays->inter.dx = st_inter.dx;
	data->rays->inter.dy = st_inter.dy;
	data->rays->h_or_v = HOR_INTER;
}

void	vertical_inter(t_data *data)
{
	t_index		st_inter;
	t_index		step;
	int			check;

	st_inter.dx = floor(data->play->player.dx / TILE_SIZE) * TILE_SIZE;
	if (data->rays->face.right)
		st_inter.dx += TILE_SIZE;
	st_inter.dy = data->play->player.dy + (st_inter.dx - data->play->player.dx) * tan(data->rays->angle);
	step.dx = TILE_SIZE;
	check = 0;
	if (data->rays->face.left)
	{
		step.dx *= -1;
		check = 1;
	}
	step.dy = step.dx * tan(data->rays->angle);
	if (step.dy > 0 && data->rays->face.up)
		step.dy *= -1;
	if (step.dy < 0 && data->rays->face.down)
		step.dy *= -1;
	while (!check_rayWall(data, st_inter.dx - check, st_inter.dy))
	{
		if (check_rayDoor(data, st_inter.dx, st_inter.dy - check))
		{
			st_inter.var = sqrtf(pow((st_inter.dx - data->play->player.dx), 2) + pow((st_inter.dy - data->play->player.dy), 2));
			if (!data->rays->if_is_door || data->rays->door_inter.var > st_inter.var)
			{
				printf("%d  :  ", data->rays->where_D);
				puts("V");
				data->rays->if_is_door = true;
				data->rays->door_inter.dx = st_inter.dx + 1;
				data->rays->door_inter.dy = st_inter.dy;
				data->rays->door_inter.var = st_inter.var;
				data->rays->where_D = VER_INTER;
			}
		}
		st_inter.dx += step.dx;
		st_inter.dy += step.dy;
	}
	st_inter.var = sqrtf(pow((st_inter.dx - data->play->player.dx), 2) + pow((st_inter.dy - data->play->player.dy), 2));
	if (st_inter.var < data->rays->distance)
	{
		data->rays->distance = st_inter.var;
		data->rays->inter.dx = st_inter.dx;
		data->rays->inter.dy = st_inter.dy;
		data->rays->h_or_v = VER_INTER;
	}
}
