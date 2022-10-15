/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:06:17 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/10/13 18:23:29 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_player_data(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (ft_strchr("NEWS",data->map[y][x]))
			{
				data->play->player.dx = (x + 0.5) * TILE_SIZE;
				data->play->player.dy = (y + 0.5) * TILE_SIZE;
				init_angle(data, data->map[y][x]);
				break ;
			}
			x++;
		}
		y++;
	}
}

void    init_angle(t_data *data, char player)
{
	if (player == 'N')
		data->play->view_angle = M_PI / 2;
	else if (player == 'S')
		data->play->view_angle = 3 * M_PI / 2;
	else if (player == 'W')
		data->play->view_angle = M_PI;
	else if (player == 'E')
		data->play->view_angle = 0;
}

void	opening_texture(t_data *data)
{
	data->texture->nor_f = ft_strdup("textures/wall_1.xpm");
	data->texture->sou_f = ft_strdup("textures/wall_2.xpm");
	data->texture->wes_f = ft_strdup("textures/wall_3.xpm");
	data->texture->eas_f = ft_strdup("textures/wall_4.xpm");
	if (open(data->texture->nor_f, O_RDONLY) < 0 || open(data->texture->wes_f, O_RDONLY) < 0 || \
		open(data->texture->eas_f, O_RDONLY) < 0 || open(data->texture->sou_f, O_RDONLY) < 0)
		error_exit("Texture not found", 1);
	
	//	North Textures
	data->texture->tex_img->img = mlx_xpm_file_to_image(data->mlx, data->texture->nor_f, &data->texture->n_size.x, &data->texture->n_size.y);
	data->texture->north = (int *)mlx_get_data_addr(data->texture->tex_img->img, &data->texture->tex_img->bits_per_pixel, &data->texture->tex_img->line_length, &data->texture->tex_img->endian);
	
	// South Texture
	data->texture->tex_img->img = mlx_xpm_file_to_image(data->mlx, data->texture->sou_f, &data->texture->s_size.x, &data->texture->s_size.y);
	data->texture->south = (int *)mlx_get_data_addr(data->texture->tex_img->img, &data->texture->tex_img->bits_per_pixel, &data->texture->tex_img->line_length, &data->texture->tex_img->endian);
	
	//	West Texture
	data->texture->tex_img->img = mlx_xpm_file_to_image(data->mlx, data->texture->wes_f, &data->texture->w_size.x, &data->texture->w_size.y);
	data->texture->west = (int *)mlx_get_data_addr(data->texture->tex_img->img, &data->texture->tex_img->bits_per_pixel, &data->texture->tex_img->line_length, &data->texture->tex_img->endian);
	
	//	East Texture
	data->texture->tex_img->img = mlx_xpm_file_to_image(data->mlx, data->texture->eas_f, &data->texture->e_size.x, &data->texture->e_size.y);
	data->texture->east = (int *)mlx_get_data_addr(data->texture->tex_img->img, &data->texture->tex_img->bits_per_pixel, &data->texture->tex_img->line_length, &data->texture->tex_img->endian);
}