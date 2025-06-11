/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:55:49 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/11 13:22:02 by akovtune         ###   ########.fr       */
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
	settings->is_minimap_visible = false;
	settings->is_clipped_minimap_visible = true;
	settings->prev_clipped_minimap_state = true;
	settings->ceiling_color = (t_color){0};
	settings->floor_color = (t_color){0};
	settings->textures = NULL;
	settings->animations = NULL;
	return (settings);
}

int	build_settings(t_settings **settings_ref)
{
	t_settings	*settings;

	if (!settings_ref || !*settings_ref)
		return (EMPTY_PTR_ERR);
	settings = *settings_ref;
	settings->textures = init_string_array(TEXTURE_NAMES_COUNT);
	if (!settings->textures)
		return (destroy_settings(settings_ref), MALLOC_FAIL_ERR);
	settings->animations = init_string_array(ANIMATION_NAMES_COUNT);
	if (!settings->animations)
		return (destroy_settings(settings_ref), MALLOC_FAIL_ERR);
	return (SUCCESS);
}

void	destroy_settings(t_settings **settings_ref)
{
	t_settings	*settings;

	if (!settings_ref || !*settings_ref)
		return ;
	settings = *settings_ref;
	if (settings->textures)
		destroy_string_array(&settings->textures);
	if (settings->animations)
		destroy_string_array(&settings->animations);
	free(settings);
	*settings_ref = NULL;
}
/*
if (settings->door_filepath)
		destroy_string(&settings->door_filepath);
*/
