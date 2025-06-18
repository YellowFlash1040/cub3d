/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_setup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:17:58 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/18 17:15:12 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animations_setup.h"

int	setup_animations(t_animations *animations, t_configuration *config)
{
	int			result;
	t_string	filepath;

	filepath = config->animations[ANIMATION_SPRITE];
	result = load_animation(filepath, 32, &animations->sprite);
	if (result != SUCCESS)
		return (result);
	filepath = config->animations[ANIMATION_NORTH_WALL];
	result = load_animation(filepath, 16, &animations->north_wall);
	if (result != SUCCESS)
		return (result);
	filepath = config->animations[ANIMATION_SOUTH_WALL];
	result = load_animation(filepath, 16, &animations->south_wall);
	if (result != SUCCESS)
		return (result);
	filepath = config->animations[ANIMATION_WEST_WALL];
	result = load_animation(filepath, 16, &animations->west_wall);
	if (result != SUCCESS)
		return (result);
	filepath = config->animations[ANIMATION_EAST_WALL];
	result = load_animation(filepath, 16, &animations->east_wall);
	if (result != SUCCESS)
		return (result);
	return (SUCCESS);
}
