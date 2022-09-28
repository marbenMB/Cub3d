/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:40:45 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/09/28 16:57:57 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_isWall(t_data *data)
{
	size_t	next_idx[2];

	next_idx[0] = (size_t)convert_todx(data->play->x_player + data->play->x_move);
	next_idx[1] = (size_t)convert_todx(data->play->y_player + data->play->y_move);
	if (data->map[next_idx[1]])
	{
		if (next_idx[0] >= ft_strlen(data->map[next_idx[1]]) || data->map[next_idx[1]][next_idx[0]] == '1')
			return (0);
	}
    return (1);
}