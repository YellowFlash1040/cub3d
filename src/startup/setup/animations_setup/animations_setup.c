/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_setup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:17:58 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/11 13:32:55 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animations_setup.h"

int	setup_animations(t_animations *animations, t_settings *settings)
{
	int			result;
	t_string	filepath;

	filepath = settings->animations[ANIMATION_SPRITE];
	result = load_animation(filepath, &animations->sprite);
	if (result != SUCCESS)
		return (result);
	filepath = settings->animations[ANIMATION_NORTH_WALL];
	result = load_animation(filepath, &animations->north_wall);
	if (result != SUCCESS)
		return (result);
	filepath = settings->animations[ANIMATION_SOUTH_WALL];
	result = load_animation(filepath, &animations->south_wall);
	if (result != SUCCESS)
		return (result);
	filepath = settings->animations[ANIMATION_WEST_WALL];
	result = load_animation(filepath, &animations->west_wall);
	if (result != SUCCESS)
		return (result);
	filepath = settings->animations[ANIMATION_EAST_WALL];
	result = load_animation(filepath, &animations->east_wall);
	if (result != SUCCESS)
		return (result);
	return (SUCCESS);
}
