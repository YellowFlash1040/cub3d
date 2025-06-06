/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clipped_minimap.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:02:35 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/06 16:54:20 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIPPED_MINIMAP_H
# define CLIPPED_MINIMAP_H

# include "minimap_helpers.h"

void	draw_clipped_minimap(t_canvas *canvas, t_map *map, t_player *player);

void	draw_clipped_map(t_canvas *canvas, t_point start_point, t_map *map,
			t_player *player);
void	draw_clipped_player(t_canvas *canvas, t_point start_point,
			t_player *player, t_size map_size);

#endif
