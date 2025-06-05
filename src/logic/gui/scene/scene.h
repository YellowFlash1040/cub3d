/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:21:52 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/05 14:51:16 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "drawing.h"
# include "camera.h"
# include "settings.h"
# include "textures.h"
# include "geometry.h"
# include "map.h"

void	draw_scene(t_canvas *canvas, t_camera *camera, t_textures *textures,
			t_map *map);
void	draw_surface(t_canvas *canvas, t_surface *surface);
void	draw_walls(t_canvas *canvas, t_camera *camera, t_textures *textures,
			t_map *map);

#endif
