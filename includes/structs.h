/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:09:51 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/10/12 18:26:44 by mbenbajj         ###   ########.fr       */
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

typedef	struct	s_int_dx
{
	int	x;
	int	y;
}	t_int_dx;

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
	double			wall_height;
}	t_ray;

typedef struct s_texture
{
	char		*nor_f;
	char		*sou_f;
	char		*eas_f;
	char		*wes_f;
	t_img		*tex_img;
	int			*north;
	int			*south;
	int			*east;
	int			*west;
	double		zoom_factor;
	t_int_dx	n_size;
	t_int_dx	s_size;
	t_int_dx	e_size;
	t_int_dx	w_size;
}	t_texture;

typedef struct s_data
{
	void		*mlx;
	void		*win;
    char    	**map;
	int			map_height;
	int			map_width;
	t_img		*img;
	t_play		*play;
	t_key		*hooks;
	t_ray		*rays;
	t_texture	*texture;
	bool		if_2d;
	
}	t_data;

#endif