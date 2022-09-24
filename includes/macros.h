/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:19:49 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/09/24 16:37:58 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MACROS_H
#define _MACROS_H

# include "cub3d.h"

//	***		FD
#define STD_IN 0
#define STD_OUT 1
#define STD_ERR 2

//	***		STAT
#define SUCC 0
#define FAIL -1

//	***		WIN_SIZES
#define WIDTH 1600
#define HEIGHT 1200

//	***		DRAW_SIZES
#define TILE_SIZE 32
#define LINE_LEN (TILE_SIZE / 2)

//	***		COLORS
#define WHITE 0xffffff
#define BLACK 0x000000
#define YELLOW 0xffff00 
#define RED 0xff0000

//	***		KEYS
#define	ESC 53
#define ROW_LEFT 123
#define ROW_RIGHT 124
#define PLAY_UP 13
#define PLAY_DOWN 1
#define PLAY_LEFT 0
#define	PLAY_RIGHT 2

//  ***     ANGLE
#define ONE_RAD 1

#endif