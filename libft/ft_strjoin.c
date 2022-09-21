/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:07:09 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/04/27 00:30:45 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l_s1;
	int		l_s2;
	int		j;
	char	*str;

	if (s1 && s2)
	{
		l_s1 = ft_strlen((char *)s1);
		l_s2 = ft_strlen((char *)s2);
		str = (char *)malloc ((l_s1 + l_s2 + 1) * sizeof(char));
		if (!str)
			exit(1);
		j = 0;
		if ((l_s2 + l_s1))
		{
			while (l_s1 && l_s1--)
				str[j++] = (char )*s1++;
			while ((l_s1 == 0) && l_s2--)
				str[j++] = (char )*s2++;
		}
		str[j] = 0;
		return (str);
	}
	return (0);
}
