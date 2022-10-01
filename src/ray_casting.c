/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:15:32 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/10/01 18:44:33 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	casting(t_data *data, int color)
{
	int		id;
	
	color++;
	id = 0;
	data->rays->angle = data->play->view_angle - (FOV / 2);
	while (id < NUM_RAYS)
	{
		draw_2d_line(data, data->play->x_player + (cos(data->rays->angle) * LINE_LEN * 2), data->play->y_player + (sin(data->rays->angle) * LINE_LEN * 2), PINK);
		data->rays->id = id;
		data->rays->angle += (FOV / NUM_RAYS);
		// printf("	+>	%d : %f\n", data->rays->id, data->rays->angle);
		id++;
	}
}
