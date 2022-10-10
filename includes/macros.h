/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:19:49 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/10/10 11:52:36 by mbenbajj         ###   ########.fr       */
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
#define TILE_SIZE 5
#define LINE_LEN (TILE_SIZE)
#define STEP 1
#define FOV (60 * M_PI / 180)
#define NUM_RAYS (WIDTH)
#define VAR_ANG (FOV / NUM_RAYS)

//	***		COLORS
#define WHITE 0xffffff
#define BLACK 0x000000
#define YELLOW 0xffff00
#define RED 0xff0000
#define BLU  0x64e8ee
#define PINK 0xee1aae
#define GREY 0xadadad
#define GREEN 0x55ecb3

//	***		KEYS
#define	ESC 53
#define ROW_LEFT 123
#define ROW_RIGHT 124
#define PLAY_UP 13
#define PLAY_DOWN 1
#define PLAY_LEFT 0
#define	PLAY_RIGHT 2

//  ***     ANGLE
#define ADD_ANGLE 0.05

#endif