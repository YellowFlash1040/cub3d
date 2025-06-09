/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:21:52 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/07 19:27:53 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "wall_drawing.h"
# include "surface_drawing.h"

void	draw_scene(t_canvas *canvas, t_camera *camera, t_textures *textures,
			t_map *map);

#endif
