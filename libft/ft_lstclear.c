/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 03:33:52 by aboulhaj          #+#    #+#             */
/*   Updated: 2021/11/20 15:18:25 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*save;

	if (lst)
	{
		while (*lst)
		{
			save = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = save;
		}
		free (*lst);
	}
}
