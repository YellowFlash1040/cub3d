/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:45:06 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/01 15:29:54 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "settings_setup.h"

int	setup_settings(t_settings *settings)
{
	settings->player_position = (t_fpoint){280, 250};

	settings->camera_fov = CAMERA_FIELD_OF_VIEW * DEGREE;
	settings->camera_angle = 222 * M_PI / 180.0;

	//Textures fix testing
	// x: 261.294118, y: 315.295798
	// Angle: 50.146168
	settings->player_position = (t_fpoint){261.294118, 315.295798};
	settings->camera_angle = 50.146168 * M_PI / 180.0;

	settings->ceiling_color = 0xffaaaaff;
	settings->floor_color = 0xaaaaffff;
	settings->north_wall_filepath = ft_strdup("./assets/wall4.png"); //needs to be mirrored
	settings->south_wall_filepath = ft_strdup("./assets/wall4.png"); //is fine
	settings->west_wall_filepath = ft_strdup("./assets/wall5.png"); //is fine
	settings->east_wall_filepath = ft_strdup("./assets/wall5.png"); //needs to be mirrored

	return (SUCCESS);
}
