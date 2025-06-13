/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_settings.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:47:49 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/13 13:47:22 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_SETTINGS_H
# define CAMERA_SETTINGS_H

// How many rays camera casts
// # define RAYS_COUNT 128
# define RAYS_COUNT 120
// # define RAYS_COUNT 100
//Player's/camera's field of view in degrees (not radians)
# define CAMERA_FIELD_OF_VIEW 60
//Player's/camera's rotation speed in units per second
# define ROTATION_SPEED 2
//Player's/camera's horizontal/vertical movement speed in units per second
// # define MOVEMENT_SPEED 100
# define MOVEMENT_SPEED 300

#endif

/*
GAME SCREEN SIZE PROBLEM

Thought 1:
In order to understand how wide a line on the screen needs to be
you need to divide window width by amount of rays
line_width = WINDOW_WIDTH / RAYS_COUNT

Thought 2:
In order for your game screen (scene) to look nice,
the GAME_SCREEN_WIDTH has to be divisible by RAYS_COUNT without a remainder
*/

/*
TEXTURES PROBLEM

Some of the textures (north side and east side) are being mirrored

It has something to do with the side a ray is facing
and with x and y coordinates, but I'm not quite sure why exactly
*/
