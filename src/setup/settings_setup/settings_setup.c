/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:45:06 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/02 12:55:07 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "settings_setup.h"

int	setup_settings(t_settings *settings)
{
	t_point		grid_player_position;
	t_direction	grid_player_direction;

	grid_player_position = (t_point){3, 6};
	grid_player_direction = NORTH;

	/*----------------------------------------*/
	// Manual setup for debugging purposes
	/*----------------------------------------*/
	settings->player_position = (t_fpoint){280, 250};

	settings->camera_fov = CAMERA_FIELD_OF_VIEW * DEGREE;
	settings->camera_angle = 222 * M_PI / 180.0;

	//Textures fix testing
	// x: 261.294118, y: 315.295798
	// Angle: 50.146168
	settings->player_position = (t_fpoint){261.294118, 315.295798};
	settings->camera_angle = 50.146168 * M_PI / 180.0;

	//Camera field of view tests
	// x: 256.421416, y: 445.943927
	// Angle: 90.744839
	settings->player_position = (t_fpoint){256.421416, 445.943927};
	settings->camera_angle = 90.744839 * M_PI / 180.0;

	/*----------------------------------------*/
	// Preparing for the actual game setup
	/*----------------------------------------*/
	int x = grid_player_position.x * CELL_SIZE + CELL_SIZE / 2;
	int y = grid_player_position.y * CELL_SIZE + CELL_SIZE / 2;
	settings->player_position = (t_fpoint){x, y};
	if (grid_player_direction == NORTH)
		settings->camera_angle = 91 * M_PI / 180.0;
	else if (grid_player_direction == SOUTH)
		settings->camera_angle = 271 * M_PI / 180.0;
	else if (grid_player_direction == WEST)
		settings->camera_angle = 181 * M_PI / 180.0;
	else
		settings->camera_angle = 1 * M_PI / 180.0;

	settings->ceiling_color = 0xffaaaaff;
	settings->floor_color = 0xaaaaffff;
	settings->north_wall_filepath = ft_strdup("./assets/wall4.png"); //needs to be mirrored
	settings->south_wall_filepath = ft_strdup("./assets/wall4.png"); //is fine
	settings->west_wall_filepath = ft_strdup("./assets/wall4.png"); //is fine
	settings->east_wall_filepath = ft_strdup("./assets/wall4.png"); //needs to be mirrored

	return (SUCCESS);
}
