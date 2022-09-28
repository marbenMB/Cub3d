/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:09:51 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/09/28 16:16:58 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STRUCTS_H
#define _STRUCTS_H

# include "cub3d.h"

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_play
{
	double	x_player;
	double	y_player;
	double	x_move;
	double	y_move;
	double	view_angle;
}	t_play;

typedef struct s_key
{
	int		row_left;
	int		row_right;
	int		key_up;
	int		key_donw;
	int		key_left;
	int		key_right;
}	t_key;


typedef struct s_data
{
	void	*mlx;
	void	*win;
    char    **map;
	int		map_height;
	int		map_width;
	t_img	*img;
	t_play	*play;
	t_key	*hooks;
	
}	t_data;

#endif