/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_settings.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:47:49 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/01 18:52:28 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_SETTINGS_H
# define CAMERA_SETTINGS_H

# define RAYS_COUNT 120
# define CAMERA_FIELD_OF_VIEW 60
// # define ROTATION_ANGLE 0.05
# define ROTATION_SPEED 2
//Player's/camera's speed in units per second
# define MOVEMENT_SPEED 100

#endif

/*
GAME SCREEN SIZE PROBLEM

In order to understand how wide a line on the screen needs to be
you need to divide window width by amount of rays
line_width = WINDOW_WIDTH / RAYS_COUNT
*/

/*
TEXTURES PROBLEM

Some of the textures (north side and east side) are being mirrored

I think (because I remember some of the information from 3dsage's video)
that it has something to do with x and y coordinates
*/