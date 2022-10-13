/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:59:22 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/10/13 18:21:56 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rendering_wall(t_data *data)
{
	double  dist_ppp;
	double  proj_p;

	dist_ppp = (WIDTH / 2) / tan(FOV / 2);
	data->rays->distance *= cos(data->rays->angle - data->play->view_angle);
	proj_p = (TILE_SIZE / data->rays->distance) * dist_ppp;
	data->rays->wall_height = proj_p;
	if (proj_p > HEIGHT)
		proj_p = HEIGHT;
	draw_3d_wall(data, proj_p, GREY);
}

void	draw_3d_wall(t_data *data, double proj_p, int color)
{
	t_index first_pt;
	t_index next_pt;

	first_pt.dy = (HEIGHT / 2) - (proj_p / 2);
	if (first_pt.dy < 0)
		first_pt.dy = 0;
	next_pt.dy = first_pt.dy + proj_p;
	// if (proj_p > HEIGHT)
	// 	proj_p = HEIGHT;
	if (next_pt.dy > HEIGHT)
		next_pt.dy = HEIGHT;
	while (first_pt.dy <= next_pt.dy)
	{
		color = rendering_texColor(data, first_pt.dy);
		ft_mlx_pixel_put(data, data->rays->id, first_pt.dy, color);
		first_pt.dy++;
	}
}

int	rendering_texColor(t_data *data, int tex_y)
{
	t_index		tex;
	t_int_dx	i_tex;
	double	zoom_factor;

	zoom_factor = (double)data->texture->n_size.y / data->rays->wall_height;
	tex.dy = tex_y + ((data->rays->wall_height / 2) - (HEIGHT / 2));
	if (tex.dy < 0)
		tex.dy = 0;
	tex.dx = data->rays->inter.dx;
	if (data->rays->h_or_v == 2)
		tex.dx = data->rays->inter.dy;
	tex.dx /= TILE_SIZE;
	tex.dx -= floor(tex.dx);
	tex.dx *= data->texture->n_size.x;
	tex.dy *=  zoom_factor;
	tex.dy = floor(tex.dy);
	tex.dy *= data->texture->n_size.x;
	i_tex.x = (int)tex.dx;
	i_tex.y = (int)tex.dy;

	return (data->texture->north[i_tex.x + i_tex.y]);
}