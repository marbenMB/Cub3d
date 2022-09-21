/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:17:11 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/09/21 16:43:05 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

void    error_exit(char *msg, int exit_stat)
{
    ft_putendl_fd(msg, STD_ERR);
    exit(exit_stat);
}