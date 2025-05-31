/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:55:49 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/31 16:59:57 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "settings.h"

t_settings	*init_settings(void)
{
	t_settings	*settings;

	settings = (t_settings *)malloc(sizeof(t_settings));
	if (!settings)
		return (NULL);
	settings->player_position = (t_fpoint){0};
	settings->camera_fov = 0;
	settings->camera_angle = 0;
	settings->is_minimap_visible = true;
	settings->ceiling_color = (t_color){0};
	settings->floor_color = (t_color){0};
	settings->north_wall_filepath = NULL;
	settings->south_wall_filepath = NULL;
	settings->west_wall_filepath = NULL;
	settings->east_wall_filepath = NULL;
	return (settings);
}

void	destroy_settings(t_settings **settings_ref)
{
	t_settings	*settings;

	if (!settings_ref || !*settings_ref)
		return ;
	settings = *settings_ref;
	if (settings->north_wall_filepath)
		destroy_string(&settings->north_wall_filepath);
	if (settings->south_wall_filepath)
		destroy_string(&settings->south_wall_filepath);
	if (settings->west_wall_filepath)
		destroy_string(&settings->west_wall_filepath);
	if (settings->east_wall_filepath)
		destroy_string(&settings->east_wall_filepath);
	free(settings);
	*settings_ref = NULL;
}
