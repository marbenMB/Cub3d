/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:02:28 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/10/23 12:48:38 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define PLAY_EMPT "0NSEW23"
# define PLAYER "NSEW"
# define WALL_SPAC "D1 \n	"
# define LIMIT "1 \0\n"
# define DOOR "D"
# define WHITE_SPACE "\t"

enum
{
	NO,
	SO,
	WE,
	EA,
	D1,
	D2,
	D3,
	ISWALL,
	ISDOOR,
	LAST,
	F,
	C
};

#endif