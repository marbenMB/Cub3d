/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 12:38:13 by aboulhaj          #+#    #+#             */
/*   Updated: 2021/11/10 11:24:21 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	l_dst;
	size_t	l_src;
	int		i;
	int		fin;

	l_src = ft_strlen((char *) src);
	l_dst = ft_strlen(dst);
	if (dstsize > l_dst)
		fin = l_src + l_dst;
	else
		fin = l_src + dstsize;
	i = 0;
	while (src[i] && l_dst < dstsize - 1 && dstsize != 0)
	{
		dst[l_dst] = src[i];
		l_dst++;
		i++;
	}
	dst[l_dst] = '\0';
	return (fin);
}
