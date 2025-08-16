/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:21:52 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/18 17:29:01 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "wall_drawing.h"
# include "surface_drawing.h"
# include "sprites_drawing.h"

void	draw_scene(t_canvas *canvas, t_camera *camera, t_game *game,
			t_textures *textures);

#endif
