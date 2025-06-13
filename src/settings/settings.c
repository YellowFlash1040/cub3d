/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:55:49 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/11 16:47:55 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "settings.h"

t_settings	*init_settings(void)
{
	t_settings	*settings;

	settings = (t_settings *)malloc(sizeof(t_settings));
	if (!settings)
		return (NULL);
	settings->camera_fov = CAMERA_FIELD_OF_VIEW * DEGREE;
	settings->is_minimap_visible = false;
	settings->is_clipped_minimap_visible = true;
	settings->prev_clipped_minimap_state = false;
	return (settings);
}

void	destroy_settings(t_settings **settings_ref)
{
	t_settings	*settings;

	if (!settings_ref || !*settings_ref)
		return ;
	settings = *settings_ref;
	free(settings);
	*settings_ref = NULL;
}
