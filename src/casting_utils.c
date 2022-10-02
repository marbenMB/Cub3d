/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 21:50:30 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/10/02 21:58:23 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_ray   *lst_new(int id, double angle)
{
    t_ray   *new;

    new = (t_ray *)ft_calloc(1, sizeof(t_ray));
    new->id = id;
    new->angle = angle;
	new->next = NULL;
	return (new);
}

void	lst_add_back(t_ray **lst, t_ray *new)
{
	t_ray	*head;

	head = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while (head->next)
			head = head->next;
		head->next = new;
	} 
}
