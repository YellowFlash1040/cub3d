/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:11:37 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/06 16:56:28 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

void	draw_minimap(t_canvas *canvas, t_map *map, t_player *player)
{
	draw_fullsize_minimap(canvas, map, player);
	draw_clipped_minimap(canvas, map, player);
}
