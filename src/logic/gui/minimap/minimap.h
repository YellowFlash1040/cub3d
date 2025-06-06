/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:11:43 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/06 13:10:26 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "drawing.h"
# include "game.h"
# include "rays.h"
# include "corners.h"

void	draw_minimap(t_canvas *canvas, t_map *map, t_player *player);

void	draw_map(t_canvas *canvas, t_map *map, t_point point);
void	draw_player(t_canvas *canvas, t_player *player);
void	draw_rays(t_canvas *canvas, t_camera *camera);
void	draw_grid(t_canvas *canvas, t_point point, t_size size,
			t_size cell_size);

void	draw_miniminimap(t_canvas *canvas, t_point point, t_map *map, t_player *player);
void	draw_miniplayer(t_canvas *canvas, t_point start_point, t_player *player,
			t_size map_size);
void	draw_minirays(t_canvas *canvas, t_camera *camera);

#endif
