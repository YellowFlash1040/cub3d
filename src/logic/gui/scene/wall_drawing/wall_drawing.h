/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_drawing.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:00:50 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/07 19:27:09 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WALL_DRAWING_H
# define WALL_DRAWING_H

# include "map.h"
# include "camera.h"
# include "textures.h"
# include "wall_slice_drawing.h"

void	draw_walls(t_canvas *canvas, t_camera *camera, t_textures *textures,
			t_map *map);

#endif
