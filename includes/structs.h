/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:09:51 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/10/08 15:40:23 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STRUCTS_H
#define _STRUCTS_H

# include "cub3d.h"

typedef struct	s_index
{
	double	dx;
	double	dy;
	double	var;
}	t_index;

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_play
{
	t_index	player;
	t_index	move;
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

typedef struct s_face_ray
{
	bool	up;
	bool	down;
	bool	left;
	bool	right;
}	t_face_ray;

typedef struct s_ray
{
	int				id;
	double			angle;
	t_index			inter;
	double			distance;
	t_face_ray		face;
	int				h_or_v;
	// struct s_ray	*next;
	// double	x_best;
	// double	y_best;
}	t_ray;

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
	t_ray	*rays;
	
}	t_data;

#endif