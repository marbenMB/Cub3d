/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:40:45 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/09/30 13:05:11 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_isWall(t_data *data)
{
	int	next_idx[2];

	next_idx[0] = convert_todx(data->play->x_player + data->play->x_move);
	next_idx[1] = convert_todx(data->play->y_player + data->play->y_move);
	if (data->map[next_idx[1]])
	{
		if (next_idx[0] >= (int)ft_strlen(data->map[next_idx[1]]) || data->map[next_idx[1]][next_idx[0]] == '1')
			return (0);
		if (data->map[next_idx[1]][next_idx[0] - 1] == '1' && data->map[next_idx[1] + 1][next_idx[0]] == '1')
			if (convert_todx(data->play->y_player) == next_idx[1] + 1 && convert_todx(data->play->x_player) == next_idx[0] - 1)
				return (0);
		if (data->map[next_idx[1]][next_idx[0] + 1] == '1' && data->map[next_idx[1] - 1][next_idx[0]] == '1')
			if (convert_todx(data->play->y_player) == next_idx[1] - 1 && convert_todx(data->play->x_player) == next_idx[0] + 1)
				return (0);
		if (data->map[next_idx[1]][next_idx[0] + 1] == '1' && data->map[next_idx[1]][next_idx[0] + 1] == '1')
			if (convert_todx(data->play->y_player) == next_idx[1] + 1 && convert_todx(data->play->x_player) == next_idx[0] + 1)
				return (0);
		if (data->map[next_idx[1]][next_idx[0] - 1] == '1' && data->map[next_idx[1] - 1][next_idx[0]] == '1')
			if (convert_todx(data->play->y_player) == next_idx[1] - 1 && convert_todx(data->play->x_player) == next_idx[0] - 1)
				return (0);
	}
    return (1);
}