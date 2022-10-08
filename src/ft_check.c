/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:40:45 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/10/08 15:29:47 by mbenbajj         ###   ########.fr       */
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
	if (x_move > WIDTH || x_move < 0 || y_move > HEIGHT || y_move < 0)
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