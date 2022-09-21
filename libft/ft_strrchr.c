/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:29:32 by aboulhaj          #+#    #+#             */
/*   Updated: 2021/11/10 20:19:01 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		l_str;
	char	*str;
	char	tofind;

	str = (char *)s;
	tofind = (char )c;
	l_str = ft_strlen(str);
	if (tofind == 0)
		return (&str[l_str]);
	while (l_str)
	{
		l_str--;
		if (str[l_str] == (char )c)
			return (str + l_str);
	}
	return (0);
}
