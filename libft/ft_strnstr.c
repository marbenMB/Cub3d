/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:39:54 by aboulhaj          #+#    #+#             */
/*   Updated: 2021/11/06 20:22:12 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	b;
	int	size;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] && len != 0)
	{
		b = 0;
		if (haystack[i] == needle[b])
		{
			size = len;
			while (haystack[i + b] == needle[b] && size != 0)
			{
				b++;
				size--;
				if (needle[b] == '\0' )
					return ((char *)&haystack[i]);
			}
		}
		i++;
		len--;
	}
	return (0);
}
