/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:07:32 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/09/21 20:31:36 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include "../libft/libft.h"
# include "../utils/utils.h"
# include "structs.h"
# include "macros.h"

//	************************	FUNCTIONS	************************  //
	//	----------------	FT_CUB3D	----------------  //
void	init_data(t_data *data);
void	mlx_ptr_init(t_data *data);
	//	----------------	FT_ERROR	----------------  //
void    error_exit(char *msg, int exit_stat);
	//	----------------	READ_MAP	----------------  //
void	get_parced_map(t_data *data, char *file_name);
void	map_height(int fd, t_data *data);
void	map_width(t_data *data, char *line);
void	read_map(int fd, t_data *data);
	//	----------------	FT_DRAW 	----------------  //
void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);
void	drawing(t_data *data);
void	draw_2d(t_data *data);
void	draw_2d_cube(t_data *data, int x, int y, int color);

#endif