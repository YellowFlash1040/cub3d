/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:11:43 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/25 18:22:31 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include <MLX42/MLX42.h>
# include "game.h"
# include "drawing.h"
# include "rays.h"

# define RAYS_COUNT 60

void	draw_minimap(t_canvas *canvas, t_map *map, t_player *player);

#endif
