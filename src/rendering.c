/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:59:22 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/10/08 16:15:37 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    rendering_wall(t_data *data)
{
    double  dist_ppp;
    double  proj_p;

    dist_ppp = (WIDTH / 2) / tan(FOV / 2);
    proj_p = (TILE_SIZE / data->rays->distance) * dist_ppp;

    draw_3d_wall(data, proj_p);
}

void    draw_3d_wall(t_data *data, double proj_p)
{
    t_index first_pt;
    t_index next_pt;
    
    first_pt.dy = (WIDTH / 2) - (proj_p / 2);
    if (first_pt.dy < 0)
        first_pt.dy = 0;
    next_pt.dy = first_pt.dy + proj_p;
    if (proj_p > HEIGHT)
        proj_p = HEIGHT;
	if (next_pt.dy > HEIGHT)
		next_pt.dy = HEIGHT;
	while (first_pt.dy <= next_pt.dy)
	{
		ft_mlx_pixel_put(data, data->rays->id, first_pt.dy, WHITE);
		first_pt.dy++;
	}
}