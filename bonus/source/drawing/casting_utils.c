/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:25:07 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/10/24 05:26:27 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

t_door	*lst_new(int found, t_index inter)
{
	t_door	*door;

	door = (t_door *)ft_calloc(1, sizeof(t_door));
	door->found_h = 0;
	door->found_v = 0;
	if (found == 1)
	{
		door->found_h = 1;
		door->horizontal_touch.x = inter.x;
		door->horizontal_touch.y = inter.y;
	}
	else if (found == 2)
	{
		door->found_v = 1;
		door->vertical_touch.x = inter.x;
		door->vertical_touch.y = inter.y;
	}
	door->next = NULL;
	return (door);
}

t_door	*lst_last(t_door **lst)
{
	t_door	*head;

	head = *lst;
	if (head)
	{
		while (head->next->next)
			head = head->next;
	}
	return (head);
}

void	add_front(t_door **lst, t_door *new)
{
	if (!new)
		return ;
	else
	{
		new->next = (*lst);
		(*lst) = new;
	}
}

double	best_wall_distance(t_data *data, t_index *ray, t_index player)
{
	double	h_distance;
	double	v_distance;
	double	wall;

	h_distance = 0;
	v_distance = 0;
	if (data->ray.found_h_wall)
		h_distance = distance_2_point(player, data->ray.horizontal_touch);
	if (data->ray.found_v_wall)
		v_distance = distance_2_point(player, data->ray.vertical_touch);
	if (h_distance > v_distance)
	{
		(*ray).x = data->ray.vertical_touch.x;
		(*ray).y = data->ray.vertical_touch.y;
		data->ray.horizontal_best = 0;
		wall = v_distance;
	}
	else
	{
		(*ray).x = data->ray.horizontal_touch.x;
		(*ray).y = data->ray.horizontal_touch.y;
		data->ray.horizontal_best = 1;
		wall = h_distance;
	}
	return (wall);
}

void	door_distance(t_data *data, t_index player)
{
	t_door	*head;

	head = data->lst_door;
	while (head->next)
	{
		if (head->found_h)
		{
			head->distance = distance_2_point(player, head->horizontal_touch);
			head->horizontal_best = 1;
		}
		else if (head->found_v)
		{
			head->distance = distance_2_point(player, head->vertical_touch);
			head->horizontal_best = 0;
		}
		head = head->next;
	}
}
