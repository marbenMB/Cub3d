/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:15:59 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/09/19 18:14:25 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	cheak_buffer(char *str)
{
	if (str == NULL)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		else
			str++;
	}
	return (0);
}
