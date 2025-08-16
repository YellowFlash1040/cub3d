/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:29:15 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/27 17:27:25 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap_visibility.h"

void	toggle_minimap(t_settings *settings)
{
	bool	state;

	if (!settings->is_minimap_visible)
	{
		state = settings->is_clipped_minimap_visible;
		settings->prev_clipped_minimap_state = state;
		settings->is_clipped_minimap_visible = false;
		settings->is_minimap_visible = true;
	}
	else
	{
		settings->is_minimap_visible = false;
		state = settings->prev_clipped_minimap_state;
		settings->is_clipped_minimap_visible = state;
	}
}

void	toggle_clipped_minimap(t_settings *settings)
{
	bool	current_value;

	current_value = settings->is_clipped_minimap_visible;
	settings->is_clipped_minimap_visible = !current_value;
}
