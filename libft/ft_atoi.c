/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 10:57:55 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/08/30 09:33:49 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error(void)
{
	write (2, "Error\n", 6);
	exit(1);
}

void	ft_check(int m, long k)
{
	if (m == -1)
	{
		if (k > 2147483648)
			ft_error ();
	}
	else if (k > 2147483647)
		ft_error();
}

int	ft_atoi(const char *str)
{
	int		i;
	int		m;
	long	k;

	i = 0;
	k = 0;
	m = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			m = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		k = (str[i++] - '0') + (k * 10);
		ft_check(m, k);
	}
	return (k * m);
}
