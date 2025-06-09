/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:22:08 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/07 17:25:44 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	draw_scene(t_canvas *canvas, t_camera *camera, t_textures *textures,
	t_map *map)
{
	draw_surface(canvas, textures->ceiling);
	draw_surface(canvas, textures->floor);
	draw_walls(canvas, camera, textures, map);
}
