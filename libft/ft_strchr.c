/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:18:40 by aboulhaj          #+#    #+#             */
/*   Updated: 2021/11/10 20:23:07 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	find;
	char	*str;
	int		i;

	find = (char) c;
	str = (char *) s;
	i = 0;
	while (str[i] != find)
	{
		if (str[i] == 0)
			return (0);
		i++;
	}
	return (&str[i]);
}
