/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 04:28:26 by aboulhaj          #+#    #+#             */
/*   Updated: 2021/11/20 15:39:30 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*data;

	data = (t_list *) malloc(sizeof(t_list));
	if (!data)
		return (NULL);
	data->content = content;
	data->next = NULL;
	return (data);
}
