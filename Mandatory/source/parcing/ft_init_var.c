/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:51:32 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/10/24 15:26:31 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_color(t_data *data)
{
	data->texture.ceilling.t = -1;
	data->texture.ceilling.r = -1;
	data->texture.ceilling.g = -1;
	data->texture.ceilling.b = -1;
	data->texture.floor.t = -1;
	data->texture.floor.r = -1;
	data->texture.floor.g = -1;
	data->texture.floor.b = -1;
}

void	init_face(t_data *data)
{
	if (data->player.face == 'E')
		data->player.alpha = 0;
	else if (data->player.face == 'W')
		data->player.alpha = 3.14;
	else if (data->player.face == 'S')
		data->player.alpha = 1.57;
	else if (data->player.face == 'N')
		data->player.alpha = 4.71;
}

void	int_key(t_data *data)
{
	data->my_hook.key_a = 0;
	data->my_hook.key_w = 0;
	data->my_hook.key_s = 0;
	data->my_hook.key_d = 0;
	data->my_hook.key_east = 0;
	data->my_hook.key_west = 0;
}

void	init_struct(t_data *data)
{
	data->img = (t_img *)malloc(sizeof(t_img));
	data->error = NULL;
	data->texture.east.path = NULL;
	data->texture.north.path = NULL;
	data->texture.south.path = NULL;
	data->texture.west.path = NULL;
	data->texture.check = 0;
	data->texture.read_in_map = 0;
	data->player.n_player = 0;
	data->texture.is_empty_line = 0;
	data->img->d_size = 0;
	data->img->endian = 0;
	data->texture.zoom = 32;
	data->player.player_x = 0;
	data->player.player_y = 0;
	init_color(data);
	int_key(data);
}

int	color_converter(t_color *color)
{
	return ((color->r << 16) | (color->g << 8) | color->b);
}
