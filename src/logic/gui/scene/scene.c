/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:22:08 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/15 12:33:33 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	draw_scene(t_canvas *canvas, t_camera *camera, t_game *game,
	t_textures *textures)
{
	draw_surface(canvas, textures->ceiling);
	draw_surface(canvas, textures->floor);
	draw_walls(canvas, camera, textures, game->map);
	draw_sprites(canvas, camera, game, textures);
}
