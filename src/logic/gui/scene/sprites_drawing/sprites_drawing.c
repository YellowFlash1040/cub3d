/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_drawing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:09:49 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/21 12:35:00 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprites_drawing.h"

void	draw_sprites(t_canvas *canvas, t_camera *camera, t_game *game,
	t_textures *textures)
{
	t_sprite	*sprite;
	int			i;

	sprite = textures->npc_sprite;
	i = -1;
	while (++i < game->npc_count)
		draw_sprite(canvas, camera, game->npcs[i], sprite);
}
