/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:58:17 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/10/18 12:31:45 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "cub3d.h"

typedef struct s_index
{
	double	x;
	double	y;
}	t_index;

typedef struct s_index_int
{
	int	x;
	int	y;
}	t_index_int;

typedef struct s_face
{
	int	up;
	int	down;
	int	left;
	int	right;
}	t_face;

typedef struct s_color
{
	int	t;
	int	r;
	int	g;
	int	b;

}	t_color;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bit_img;
	int		d_size;
	int		endian;
	void	*mlx;
	void	*win;

}	t_img;

typedef struct s_player
{
	int		n_player;
	double	init_x_player;
	double	init_y_player;
	double	player_x;
	double	player_y;
	double	alpha;
	t_index	mouve;
	char	face;
}	t_player;

typedef struct s_var_texture
{
	char		*path;
	int			*xpm_array;
	t_index_int	tex_size;

}	t_var_texture;

typedef struct s_texture
{
	t_var_texture	north;
	t_var_texture	south;
	t_var_texture	east;
	t_var_texture	west;
	int				check;
	t_index_int		map_size;
	int				is_empty_line;
	int				read_in_map;
	int				zoom;
	t_color			floor;
	t_color			ceilling;

}	t_texture;

typedef struct s_ray
{
	t_face	ray_face;
	int		found_h_wall;
	int		found_v_wall;
	int		horizontal_best;
	t_index	vertical_touch;
	t_index	horizontal_touch;
	double	angle_ray;
	double	wall_height;
}	t_ray;

typedef struct s_hook
{
	int	key_east;
	int	key_west;
	int	key_w;
	int	key_d;
	int	key_s;
	int	key_a;
}	t_hook;

typedef struct s_data
{
	t_texture	texture;
	t_player	player;
	t_img		*img;
	char		**map;
	char		*error;
	t_hook		my_hook;
	t_ray		ray;

}	t_data;

#endif