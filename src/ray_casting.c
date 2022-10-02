/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:15:32 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/10/02 23:14:01 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	create_rays(t_data *data)
{
	t_ray	ray;
	
	ray.id = 0;
	ray.angle = data->play->view_angle - (FOV / 2);
	normilize_angle(&ray.angle);
	while (ray.id < NUM_RAYS)
	{
		ray.angle += (FOV / NUM_RAYS);
		lst_add_back(&data->rays, lst_new(ray.id, ray.angle));
		ray.id++;
	}
}

void	casting(t_data *data)
{
	t_ray	*head;
	double	angle;
	
	head = data->rays;
	angle = data->play->view_angle - (FOV / 2);
	normilize_angle(&angle);
	while (data->rays)
	{
		data->rays->angle = angle;
		printf("+> %d : %f\n", data->rays->id, data->rays->angle);
		angle += (FOV / NUM_RAYS);
		data->rays = data->rays->next;
	}
	data->rays = head;
}

void	draw_fov(t_data *data, int color)
{
	t_ray	*ray;

	ray = data->rays;
	while (ray)
	{
		draw_2d_line(data, data->play->x_player + (cos(ray->angle) * LINE_LEN * 2), data->play->y_player + (sin(ray->angle) * LINE_LEN * 2), color);
		ray = ray->next;
	}
}

// void	horizental_inter(t_data *data)
// {
// 	int		indx[2];

// 	indx[1] = floorf(data->play->y_player / TILE_SIZE) * TILE_SIZE;
// 	indx[0] = data->play->x_player + (data->play->y_player - indx[1]) / tan(data->rays->angle);
// 	while (data->map[indx[1]][indx[0]] != 1)
// 	{
		
// 	}
// }
