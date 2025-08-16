/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:55:33 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/13 16:54:36 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"

t_sprite	*init_sprite(void)
{
	t_sprite	*sprite;

	sprite = (t_sprite *)malloc(sizeof(t_sprite));
	if (!sprite)
		return (NULL);
	sprite->texture = NULL;
	return (sprite);
}

void	destroy_sprite(t_sprite **sprite_ref)
{
	t_sprite	*sprite;

	if (!sprite_ref || !*sprite_ref)
		return ;
	sprite = *sprite_ref;
	free(sprite);
	*sprite_ref = NULL;
}
