/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:03:51 by aboulhaj          #+#    #+#             */
/*   Updated: 2021/11/15 21:45:23 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (0);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	str = (char *)malloc ((len + 1) * sizeof(char));
	if (str)
	{
		i = 0;
		j = 0;
		while ((char )s[i])
		{
			if (i >= start && j < len)
				str[j++] = (char )s[i];
			i++;
		}
		str[j] = '\0';
		return (str);
	}
	return (0);
}
