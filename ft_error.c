/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:17:11 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/09/19 15:21:39 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void    error_exit(char *msg, int exit_stat)
{
    ft_putendl_fd(msg, STD_ERR);
    exit(exit_stat);
}