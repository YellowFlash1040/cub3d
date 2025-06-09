/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_drawing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:56:03 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/06 15:32:38 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

void	draw_player(t_canvas *canvas, t_point point, t_player *player)
{
	t_size	size;
	t_point	position;

	size = (t_size){MINIMAP_PLAYER_SIZE, MINIMAP_PLAYER_SIZE};
	position = scale_position(player->position);
	apply_offset(&position, point);
	position.x -= size.width / 2;
	position.y -= size.height / 2;
	draw_rectangle(canvas, position, size, PLAYER_COLOR);
}

void	draw_rays(t_canvas *canvas, t_point point, t_camera *camera)
{
	t_fpoint	hit;
	t_point		camera_pos;
	t_point		wall;
	int			i;

	camera_pos = scale_position(camera->position);
	apply_offset(&camera_pos, point);
	i = -1;
	while (++i < camera->rays_count)
	{
		hit = camera->rays[i].position;
		wall = scale_position(hit);
		apply_offset(&wall, point);
		draw_line(canvas, camera_pos, wall, RAY_COLOR);
	}
}
