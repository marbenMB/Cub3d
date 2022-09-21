/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 01:57:04 by aboulhaj          #+#    #+#             */
/*   Updated: 2021/11/16 01:59:23 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dst;
	int		i;
	int		len;

	if (!s)
		return (0);
	len = ft_strlen(s) + 1;
	dst = (char *)malloc(len * sizeof(char));
	i = 0;
	if (dst)
	{
		while (s[i])
		{
			dst[i] = f(i, s[i]);
			i++;
		}
		dst[i] = 0;
		return (dst);
	}
	return (0);
}
