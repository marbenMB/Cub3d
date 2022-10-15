/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:07:32 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/10/13 17:39:01 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <libc.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "/Users/marouanebenbajja/MiniLibX/minilibx_macos/mlx.h"
# include <math.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "../utils/utils.h"
# include "structs.h"
# include "macros.h"

//	************************	FUNCTIONS	************************  //
	//	----------------	FT_CUB3D	----------------  //
void	init_data(t_data *data);
void	ft_mlx_ptr_init(t_data *data, int call);
void	ft_mlx_hooking(t_data *data);
	//	----------------	FT_ERROR	----------------  //
void    error_exit(char *msg, int exit_stat);
	//	----------------	READ_MAP	----------------  //
void	get_parced_map(t_data *data, char *file_name);
void	map_height(int fd, t_data *data);
void	map_width(t_data *data, char *line);
void	read_map(int fd, t_data *data);
	//	----------------	PLAY_DATA 	----------------  //
void	get_player_data(t_data *data);
void    init_angle(t_data *data, char player);
void	opening_texture(t_data *data);
	//	----------------	FT_DRAW 	----------------  //
void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);
void	drawing(t_data *data);
void	draw_bg(t_data *data);
void	draw_2d(t_data *data);
void	draw_2d_cube(t_data *data, int x, int y, int color);
void	draw_2d_player(t_data *data, int color);
void	draw_2d_line(t_data *data, t_index first, t_index next, int color);
	//	----------------	KEY_HANDLE 	----------------  //
void	ft_destroy_all(t_data *data);
int		update_display(t_data *data);
int 	ft_key_press(int key, t_data *data);
int		ft_key_release(int key, t_data *data);
void	check_key_press(int key, t_data *data);
void	play_key(t_data *data);
void	row_press(t_data *data);
	//	----------------	FT_CHECK 	----------------  //
int		check_isWall(t_data *data, double x_move, double y_move);
int		check_rayWall(t_data *data, double x_move, double y_move);
void	check_playFace(t_ray *ray);
int		*check_TexFace(t_data *data);
	//	----------------	FT_UTILS 	----------------  //
void	normilize_angle(double *angle);
int		convert_todx(double a);
int		tab_len(char **tab);
void	free_stc(t_data *data);
void	free_tab(char **tab);
	//	----------------	RAY_CAST 	----------------  //
void	casting(t_data *data);
void	init_rayData(t_data *data);
void	horizontal_inter(t_data *data);
void	vertical_inter(t_data *data);
	//	---------------- RENDeRING FUNC  ----------------  //
void	rendering_wall(t_data *data);
void	draw_3d_wall(t_data *data, double proj_p, int color);
int		rendering_texColor(t_data *data, int tex_y, int *tex_buff);

#endif