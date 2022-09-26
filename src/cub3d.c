/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:07:09 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/09/26 17:03:39 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		printf("\x1b[31m Error in arguments \033[0m\n");
		return (1);
	}
    init_data(&data);
	get_parced_map(&data, av[1]);
	get_player_data(&data);
	ft_mlx_ptr_init(&data, 0);
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
	data->play->x_player = -1;
	data->play->y_player = -1;
	data->play->x_move = 0;
	data->play->y_move = 0;
	data->play->view_angle = tan(M_PI / 2);
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
	// mlx_hook(data->win, 03, 0, ft_key_release, data);
}
