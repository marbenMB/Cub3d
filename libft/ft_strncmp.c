/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:02:51 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/03/31 10:58:38 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*src1;
	unsigned char	*src2;

	i = 0;
	src1 = (unsigned char *)s1;
	src2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while ((src1[i] == src2[i]) && (src1[i] != '\0'))
	{
		if (i < (n - 1))
			i++;
		else
			return (0);
	}
	return (src1[i] - src2[i]);
}
