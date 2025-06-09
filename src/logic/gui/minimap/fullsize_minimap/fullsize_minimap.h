/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fullsize_minimap.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:46:13 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/06 16:51:00 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FULLSIZE_MINIMAP_H
# define FULLSIZE_MINIMAP_H

# include "minimap_helpers.h"

void	draw_fullsize_minimap(t_canvas *canvas, t_map *map, t_player *player);

void	draw_map(t_canvas *canvas, t_point point, t_map *map);
void	draw_player(t_canvas *canvas, t_point point, t_player *player);
void	draw_rays(t_canvas *canvas, t_point point, t_camera *camera);

#endif
