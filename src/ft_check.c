/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:40:45 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/10/22 01:43:50 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_isWall(t_data *data, double x_move, double y_move)
{
	int	next_idx[2];

	next_idx[0] = convert_todx(data->play->player.dx + x_move);
	next_idx[1] = convert_todx(data->play->player.dy + y_move);
	if (next_idx[1] < 0 || next_idx[0] < 0)
		return (1);
	if (data->map[next_idx[1]])
	{
		if (next_idx[0] >= (int)ft_strlen(data->map[next_idx[1]]) || data->map[next_idx[1]][next_idx[0]] == '1')
			return (1);
		if (data->map[next_idx[1]][next_idx[0] - 1] == '1' && data->map[next_idx[1] + 1][next_idx[0]] == '1')
			if (convert_todx(data->play->player.dy) == next_idx[1] + 1 && convert_todx(data->play->player.dx) == next_idx[0] - 1)
				return (1);
		if (data->map[next_idx[1]][next_idx[0] + 1] == '1' && data->map[next_idx[1] - 1][next_idx[0]] == '1')
			if (convert_todx(data->play->player.dy) == next_idx[1] - 1 && convert_todx(data->play->player.dx) == next_idx[0] + 1)
				return (1);
		if (data->map[next_idx[1]][next_idx[0] + 1] == '1' && data->map[next_idx[1]][next_idx[0] + 1] == '1')
			if (convert_todx(data->play->player.dy) == next_idx[1] + 1 && convert_todx(data->play->player.dx) == next_idx[0] + 1)
				return (1);
		if (data->map[next_idx[1]][next_idx[0] - 1] == '1' && data->map[next_idx[1] - 1][next_idx[0]] == '1')
			if (convert_todx(data->play->player.dy) == next_idx[1] - 1 && convert_todx(data->play->player.dx) == next_idx[0] - 1)
				return (1);
	}
    return (0);
}

int	check_rayWall(t_data *data, double x_move, double y_move)
{
		int	next_idx[2];

	next_idx[0] = convert_todx(x_move);
	next_idx[1] = convert_todx(y_move);
	if (x_move > data->map_width * TILE_SIZE || x_move < 0 || y_move > data->map_height * TILE_SIZE || y_move < 0)
		return (-1);
	if (next_idx[1] < 0 || next_idx[0] < 0 || next_idx[1] >= tab_len(data->map))
		return (1);
	if (data->map[next_idx[1]])
	{
		if (next_idx[0] >= (int)ft_strlen(data->map[next_idx[1]]) || data->map[next_idx[1]][next_idx[0]] == '1')
			return (1);
	}
    return (0);
}

int	check_rayDoor(t_data *data, double x_move, double y_move)
{
	t_int_dx	next;

	next.x = convert_todx(x_move);
	next.y = convert_todx(y_move);
	if (y_move >= 0 && y_move < data->map_height * TILE_SIZE && x_move >= 0 && x_move < ft_strlen(data->map[next.y]) * TILE_SIZE)
	{
		if (next.y >= 0 && data->map[next.y] && next.x >= 0 && data->map[next.y][next.x])
			if (data->map[next.y][next.x] == 'D')
				return (1);
	}
	return (0);
}

void	check_playFace(t_ray *ray)
{
	if (ray->angle > 0 && ray->angle < M_PI)
	{
		ray->face.down = true;
		ray->face.up = false;
	}
	else
	{
		ray->face.down = false;
		ray->face.up = true;
	}
	if (ray->angle > (M_PI / 2) && ray->angle < (3 * M_PI / 2))
	{
		ray->face.left = true;
		ray->face.right = false;
	}
	else
	{
		ray->face.left = false;
		ray->face.right = true;
	}
}

t_texFace	*check_TexFace(t_data *data)
{
	if (data->rays->if_is_door && data->rays->door_inter.var < data->rays->distance)
	{
		// check_DoorFace(data);
		return (data->texture->door);
	}
	if (data->rays->h_or_v == HOR_INTER)
	{
		if (data->rays->face.down)
			return (data->texture->north);
		if (data->rays->face.up)
			return (data->texture->south);
	}
	if (data->rays->h_or_v == VER_INTER)
	{
		if (data->rays->face.left)
			return (data->texture->east);
		if (data->rays->face.right)
			return (data->texture->west);
	}
	return (NULL);
}

t_texFace	*check_DoorFace(t_data *data)
{
	return (data->texture->door);
}