/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:06:17 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/10/18 22:20:16 by mbenbajj         ###   ########.fr       */
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
	data->texture->north->file = ft_strdup("textures/wall_1.xpm");
	data->texture->south->file = ft_strdup("textures/wall_2.xpm");
	data->texture->west->file = ft_strdup("textures/wall_3.xpm");
	data->texture->east->file = ft_strdup("textures/wall_4.xpm");
	data->texture->door->file = ft_strdup("textures/wood.xpm");
	if (open(data->texture->north->file, O_RDONLY) < 0 || open(data->texture->west->file, O_RDONLY) < 0 || \
		open(data->texture->east->file, O_RDONLY) < 0 || open(data->texture->south->file, O_RDONLY) < 0 || \
		open(data->texture->door->file, O_RDONLY) < 0)
		error_exit("Texture not found", 1);
	
	//	Door Textures : 
	data->texture->tex_img->img = mlx_xpm_file_to_image(data->mlx, data->texture->door->file, &data->texture->door->size.x, &data->texture->door->size.y);
	printf("door -> %d - %d\n", data->texture->door->size.x, data->texture->door->size.y);
	data->texture->door->buffer = (int *)mlx_get_data_addr(data->texture->tex_img->img, &data->texture->tex_img->bits_per_pixel, &data->texture->tex_img->line_length, &data->texture->tex_img->endian);
	
	//	North Textures
	data->texture->tex_img->img = mlx_xpm_file_to_image(data->mlx, data->texture->north->file, &data->texture->north->size.x, &data->texture->north->size.y);
	printf("north -> %d - %d\n", data->texture->north->size.x, data->texture->north->size.y);
	data->texture->north->buffer = (int *)mlx_get_data_addr(data->texture->tex_img->img, &data->texture->tex_img->bits_per_pixel, &data->texture->tex_img->line_length, &data->texture->tex_img->endian);
	
	// South Texture
	data->texture->tex_img->img = mlx_xpm_file_to_image(data->mlx, data->texture->south->file, &data->texture->south->size.x, &data->texture->south->size.y);
	printf("south -> %d - %d\n", data->texture->south->size.x, data->texture->south->size.y);
	data->texture->south->buffer = (int *)mlx_get_data_addr(data->texture->tex_img->img, &data->texture->tex_img->bits_per_pixel, &data->texture->tex_img->line_length, &data->texture->tex_img->endian);
	
	//	West Texture
	data->texture->tex_img->img = mlx_xpm_file_to_image(data->mlx, data->texture->west->file, &data->texture->west->size.x, &data->texture->west->size.y);
	printf("west -> %d - %d\n", data->texture->west->size.x, data->texture->west->size.y);
	data->texture->west->buffer = (int *)mlx_get_data_addr(data->texture->tex_img->img, &data->texture->tex_img->bits_per_pixel, &data->texture->tex_img->line_length, &data->texture->tex_img->endian);
	
	//	East Texture
	data->texture->tex_img->img = mlx_xpm_file_to_image(data->mlx, data->texture->east->file, &data->texture->east->size.x, &data->texture->east->size.y);
	printf("east -> %d - %d\n", data->texture->east->size.x, data->texture->east->size.y);
	data->texture->east->buffer = (int *)mlx_get_data_addr(data->texture->tex_img->img, &data->texture->tex_img->bits_per_pixel, &data->texture->tex_img->line_length, &data->texture->tex_img->endian);
}