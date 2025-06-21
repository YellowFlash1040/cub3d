/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:23:37 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/21 13:29:46 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animations.h"

t_animations	*init_animations(void)
{
	t_animations	*animations;

	animations = (t_animations *)malloc(sizeof(t_animations));
	if (!animations)
		return (NULL);
	animations->north_wall = NULL;
	animations->south_wall = NULL;
	animations->west_wall = NULL;
	animations->east_wall = NULL;
	animations->door = NULL;
	animations->sprite = NULL;
	return (animations);
}

int	build_animations(t_animations **animations_ref)
{
	t_animations	*animations;

	if (!animations_ref || !*animations_ref)
		return (EMPTY_PTR_ERR);
	animations = *animations_ref;
	animations->north_wall = init_animation();
	if (!animations->north_wall)
		return (destroy_animations(animations_ref), MALLOC_FAIL_ERR);
	animations->south_wall = init_animation();
	if (!animations->south_wall)
		return (destroy_animations(animations_ref), MALLOC_FAIL_ERR);
	animations->west_wall = init_animation();
	if (!animations->west_wall)
		return (destroy_animations(animations_ref), MALLOC_FAIL_ERR);
	animations->east_wall = init_animation();
	if (!animations->east_wall)
		return (destroy_animations(animations_ref), MALLOC_FAIL_ERR);
	animations->door = init_animation();
	if (!animations->door)
		return (destroy_animations(animations_ref), MALLOC_FAIL_ERR);
	animations->sprite = init_animation();
	if (!animations->sprite)
		return (destroy_animations(animations_ref), MALLOC_FAIL_ERR);
	return (SUCCESS);
}

void	destroy_animations(t_animations **animations_ref)
{
	t_animations	*animations;

	if (!animations_ref || !*animations_ref)
		return ;
	animations = *animations_ref;
	if (animations->north_wall)
		destroy_animation(&animations->north_wall);
	if (animations->south_wall)
		destroy_animation(&animations->south_wall);
	if (animations->west_wall)
		destroy_animation(&animations->west_wall);
	if (animations->east_wall)
		destroy_animation(&animations->east_wall);
	if (animations->door)
		destroy_animation(&animations->door);
	if (animations->sprite)
		destroy_animation(&animations->sprite);
	free(animations);
	*animations_ref = NULL;
}
