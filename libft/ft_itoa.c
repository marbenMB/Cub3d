/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 10:38:55 by aboulhaj          #+#    #+#             */
/*   Updated: 2021/11/20 15:10:47 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_calc(char *str, long nb, int len)
{
	while (nb > 0 && len--)
	{
		str[len] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nb;

	nb = (long)n;
	len = ft_len(nb);
	if (n == 0)
		len = 1;
	str = (char *)malloc ((len + 1) * sizeof(char));
	if (str)
	{
		str[len] = 0;
		if (n == 0)
			str[0] = '0';
		if (nb < 0)
		{
			nb = -nb;
			str[0] = '-';
		}
		if (nb > 0 && len)
			ft_calc(str, nb, len);
		return (str);
	}
	return (0);
}
