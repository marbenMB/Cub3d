/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:19:39 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/10/08 19:41:33 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_destroy_all(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img->img);
	mlx_destroy_window(data->mlx, data->win);
	free_stc(data);
	exit (0);
}

int	update_display(t_data *data)
{
	row_press(data);
	play_key(data);
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
	double	idx[2];
	
	idx[0] = STEP * cos(data->play->view_angle);
	idx[1] = STEP * sin(data->play->view_angle);
	if (data->hooks->key_up)
	{
        data->play->move.dy = idx[1];
		data->play->move.dx = idx[0];
		
	}
    if (data->hooks->key_donw)
	{
        data->play->move.dy = -idx[1];
		data->play->move.dx = -idx[0];
	}
	if (data->hooks->key_right)
	{
        data->play->move.dy = idx[0];
		data->play->move.dx = -idx[1];
	}
	if (data->hooks->key_left)
	{
        data->play->move.dy = -idx[0];
		data->play->move.dx = idx[1];
	}
}

void	row_press(t_data *data)
{
	if (data->hooks->row_left)
		data->play->view_angle -= ADD_ANGLE;
	if (data->hooks->row_right)
		data->play->view_angle += ADD_ANGLE;
	normilize_angle(&data->play->view_angle);
}