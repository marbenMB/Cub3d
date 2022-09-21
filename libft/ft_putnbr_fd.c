/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 23:13:44 by aboulhaj          #+#    #+#             */
/*   Updated: 2021/11/15 01:29:12 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = (unsigned int)(n * -1);
	}
	else
		nb = (unsigned int) n;
	if (nb >= 10)
		ft_putnbr_fd((nb / 10), fd);
	ft_putchar_fd((nb % 10) + 48, fd);
}
