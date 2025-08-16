/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_settings.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:23:33 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/15 12:25:08 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_SETTINGS_H
# define MINIMAP_SETTINGS_H

// Codam PC setup
// # define MINIMAP_CELL_SIZE 32
# define MINIMAP_CELL_SIZE 28
# define MINIMAP_PLAYER_SIZE 8

// My home PC setup
// # define MINIMAP_CELL_SIZE 16
// # define MINIMAP_PLAYER_SIZE 4

# define WALL_COLOR 0xffffffff
// # define EMPTY_SPACE_COLOR 0x000000ff
# define EMPTY_SPACE_COLOR 0xaaaaaaff
# define DOOR_COLOR 0x00ffffff
# define CLOSED_DOOR_COLOR 0xff0000ff
# define OPENED_DOOR_COLOR 0x00ff00ff
# define PLAYER_COLOR 0xff0000ff
# define RAY_COLOR 0xffff00ff
// # define GRID_COLOR 0xff0000ff
// # define GRID_COLOR 0x0000ffff
# define GRID_COLOR 0xaaaaaaff

# define MINIMAP_VIEW_RADIUS 5
# define MINIMAP_WIDTH 11
# define MINIMAP_HEIGHT 11

# define MINIMAP_X_POSITION 1408
# define MINIMAP_Y_POSITION 568

#endif
