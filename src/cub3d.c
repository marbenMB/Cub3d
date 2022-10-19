/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:07:09 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/10/18 22:17:26 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ss()
{
	system("leaks cub3d");
}

int	main(int ac, char **av)
{
	t_data	data;

	// atexit(ss);
	if (ac != 2)
	{
		printf("\x1b[31m Error in arguments \033[0m\n");
		return (1);
	}
    init_data(&data);
	get_parced_map(&data, av[1]);
	get_player_data(&data);
	ft_mlx_ptr_init(&data, 0);
	opening_texture(&data);
	drawing(&data);
	ft_mlx_hooking(&data);
	mlx_loop(data.mlx);
	return (0);
}

void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->map = NULL;
	data->map_height = 0;
	data->map_width = 0;
	data->img = (t_img *)ft_calloc(1, sizeof(t_img));
	data->play = (t_play *)ft_calloc(1, sizeof(t_play));
	data->play->player.dx = -1;
	data->play->player.dy = -1;
	data->play->move.dx = 0;
	data->play->move.dy = 0;
	data->play->view_angle = tan(M_PI / 2);
	data->hooks = (t_key *)ft_calloc(1, sizeof(t_key));
	data->hooks->key_donw = 0;
	data->hooks->key_up = 0;
	data->hooks->key_right = 0;
	data->hooks->key_left = 0;
	data->hooks->row_left = 0;
	data->hooks->row_right = 0;
	data->rays = (t_ray *)ft_calloc(1, sizeof(t_ray));
	data->if_2d = false;

	data->texture = (t_texture *)ft_calloc(1, sizeof(t_texture));
	data->texture->tex_img = (t_img *)ft_calloc(1, sizeof(t_img));
	data->texture->east = (t_texFace *)ft_calloc(1, sizeof(t_texFace));
	data->texture->west = (t_texFace *)ft_calloc(1, sizeof(t_texFace));
	data->texture->north = (t_texFace *)ft_calloc(1, sizeof(t_texFace));
	data->texture->south = (t_texFace *)ft_calloc(1, sizeof(t_texFace));
	data->texture->door = (t_texFace *)ft_calloc(1, sizeof(t_texFace));
} 

void	ft_mlx_ptr_init(t_data *data, int call)
{
	if (!call)
	{
		data->mlx = mlx_init();
		data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "+> MAR_BEN <+");
	}
	data->img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bits_per_pixel, &data->img->line_length, &data->img->endian);
}

void	ft_mlx_hooking(t_data *data)
{
	mlx_hook(data->win, 02, 0, ft_key_press, data);
	mlx_hook(data->win, 03, 0, ft_key_release, data);
	mlx_loop_hook(data->mlx, update_display, data);
}
