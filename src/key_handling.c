/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:19:39 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/09/26 17:46:35 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_destroy_all(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img->img);
	mlx_destroy_window(data->mlx, data->win);
	exit (0);
}

int	update_display(t_data *data)
{
	play_key(data);
	row_press(data);
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img->img);
	ft_mlx_ptr_init(data, 1);
	drawing(data);
	return (0);
}

int ft_key_press(int key, t_data *data)
{
    
	if (key == ESC)
        ft_destroy_all(data);
	check_key_press(key, data);
    return (0);
}

int	ft_key_release(int key, t_data *data)
{
	if (key == PLAY_UP)
		data->hooks->key_up = 0;
    if (key == PLAY_DOWN)
		data->hooks->key_donw = 0;
	if (key == PLAY_RIGHT)
		data->hooks->key_right = 0;
	if (key == PLAY_LEFT)
		data->hooks->key_left = 0;
	if (key == ROW_LEFT)
		data->hooks->row_left = 0;
	if (key == ROW_RIGHT)
		data->hooks->row_right = 0;
	return (0);
}

void	check_key_press(int key, t_data *data)
{
	if (key == PLAY_UP)
		data->hooks->key_up = 1;
    if (key == PLAY_DOWN)
		data->hooks->key_donw = 1;
	if (key == PLAY_RIGHT)
		data->hooks->key_right = 1;
	if (key == PLAY_LEFT)
		data->hooks->key_left = 1;
	if (key == ROW_LEFT)
		data->hooks->row_left = 1;
	if (key == ROW_RIGHT)
		data->hooks->row_right = 1;
}

void	play_key(t_data *data)
{
	if (data->hooks->key_up)
	{
        data->play->y_move -= sin(data->play->view_angle);
		data->play->x_move -= cos(data->play->view_angle);
	}
    if (data->hooks->key_donw)
	{
        data->play->y_move += sin(data->play->view_angle);
		data->play->x_move += cos(data->play->view_angle);
	}
	if (data->hooks->key_right)
	{
        data->play->y_move -= cos(data->play->view_angle);
		data->play->x_move += sin(data->play->view_angle);
	}
	if (data->hooks->key_left)
	{
        data->play->y_move += cos(data->play->view_angle);
		data->play->x_move -= sin(data->play->view_angle);
	}
}

void	row_press(t_data *data)
{
	if (data->hooks->row_left)
		data->play->view_angle -= ADD_ANGLE;
	if (data->hooks->row_right)
		data->play->view_angle += ADD_ANGLE;
}