/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:19:39 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/09/25 17:35:42 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_destroy_all(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img->img);
	mlx_destroy_window(data->mlx, data->win);
	exit (0);
}

int ft_key_press(int key, t_data *data)
{
    
	if (key == ESC)
        ft_destroy_all(data);
	play_key(key, data);
	row_key(key, data);
	mlx_destroy_image(data->mlx, data->img->img);
	ft_mlx_ptr_init(data, 1);
	drawing(data);
    return (0);
}

void	play_key(int key, t_data *data)
{
	if (key == PLAY_UP)
	{
        data->y_move -= sin(data->view_angle);
		data->x_move -= cos(data->view_angle);
	}
    else if (key == PLAY_DOWN)
	{
        data->y_move += sin(data->view_angle);
		data->x_move += cos(data->view_angle);
	}
	else if (key == PLAY_LEFT)
	{
        data->y_move -= cos(data->view_angle);
		data->x_move += sin(data->view_angle);
	}
	else if (key == PLAY_RIGHT)
	{
        data->y_move += cos(data->view_angle);
		data->x_move -= sin(data->view_angle);
	}
}

void	row_key(int key, t_data *data)
{
	if (key == ROW_LEFT)
		data->view_angle -= ONE_RAD;
	else if (key == ROW_RIGHT)
		data->view_angle += ONE_RAD;
}