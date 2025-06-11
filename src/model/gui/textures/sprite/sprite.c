/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:55:33 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/10 20:56:03 by akovtune         ###   ########.fr       */
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
	if (sprite->texture)
		mlx_delete_texture(sprite->texture);
	free(sprite);
	*sprite_ref = NULL;
}
