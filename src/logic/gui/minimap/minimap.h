/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:11:43 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/02 20:49:26 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "drawing.h"
# include "game.h"
# include "rays.h"

void	draw_minimap(t_canvas *canvas, t_map *map, t_player *player);
void	draw_map(t_canvas *canvas, t_map *map);
void	draw_player(t_canvas *canvas, t_player *player);
void	draw_rays(t_canvas *canvas, t_camera *camera);

#endif
