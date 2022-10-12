/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:59:22 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/10/12 18:46:07 by mbenbajj         ###   ########.fr       */
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
	double	x_inter;

	first_pt.dy = (HEIGHT / 2) - (proj_p / 2);
	if (first_pt.dy < 0)
		first_pt.dy = 0;
	next_pt.dy = first_pt.dy + proj_p;
	// if (proj_p > HEIGHT)
	// 	proj_p = HEIGHT;
	if (next_pt.dy > HEIGHT)
		next_pt.dy = HEIGHT;
	x_inter = data->rays->inter.dx - floor(data->rays->inter.dx);
	while (first_pt.dy <= next_pt.dy)
	{
		// color = rendering_texColor(data, x_inter, first_pt.dy);
		ft_mlx_pixel_put(data, data->rays->id, first_pt.dy, color);
		first_pt.dy++;
	}
}

int	rendering_texColor(t_data *data, double tex_x, double tex_y)
{
	data->texture->zoom_factor = data->texture->n_size.x / data->rays->wall_height;
	return (data->texture->north[(int)(tex_y * data->texture->n_size.x * data->texture->zoom_factor + tex_x * data->texture->n_size.x)]);
}