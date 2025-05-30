/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:11:43 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/29 17:32:45 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include <MLX42/MLX42.h>
# include "game.h"
# include "drawing.h"
# include "rays.h"

void	draw_minimap(t_canvas *canvas, t_map *map, t_player *player);

#endif
