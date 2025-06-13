/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:09:31 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/13 17:13:14 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_H
# define SPRITES_H

# include "settings.h"
# include "canvas.h"
# include "drawing.h"
# include "camera.h"
# include "game.h"
# include "textures.h"
# include "geometry.h"

# include <stdio.h>

void	draw_sprites(t_canvas *canvas, t_camera *camera, t_game *game,
			t_textures *textures);
void	draw_sprite(t_canvas *canvas, t_camera *camera, t_npc npc,
			t_sprite *sprite);

#endif
