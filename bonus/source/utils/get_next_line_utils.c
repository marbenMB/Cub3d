/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:15:59 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/08/30 10:42:43 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

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
