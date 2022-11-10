/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:19:13 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/10/18 09:24:58 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

int	ft_movekey(t_data *data)
{
	check_key(data);
	mlx_clear_window(data->img->mlx, data->img->win);
	mlx_destroy_image(data->img->mlx, data->img->img);
	draw_to_img(data);
	return (0);
}

void	ft_put_pixel(int x, int y, t_data *data, int color)
{
	char	*adr;

	if ((x > 0 && x < WIDTH) && (y > 0 && y < HEIGHT))
	{
		adr = data->img->addr + (y * data->img->d_size) \
		+ (x * (data->img->bit_img / 8));
		*((unsigned int *)adr) = color;
	}
}

double	ft_diff(double x, double y)
{
	return (y - x);
}

double	distance_2_point(t_index first, t_index last)
{
	return (sqrt (pow((last.x - first.x), 2) + pow((last.y - first.y), 2)));
}

int	color_converter(t_color *color)
{
	return ((color->r << 16) | (color->g << 8) | color->b);
}
