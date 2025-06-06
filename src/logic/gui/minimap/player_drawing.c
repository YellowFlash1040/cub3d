/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_drawing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:56:03 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/06 11:43:29 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

static t_point	scale_position(t_fpoint position);

void	draw_player(t_canvas *canvas, t_player *player)
{
	t_size	size;
	t_point	position;

	size = (t_size){MINIMAP_PLAYER_SIZE, MINIMAP_PLAYER_SIZE};
	position = scale_position(player->position);

	position.x -= size.width / 2;
	position.y -= size.height / 2;

	draw_rectangle(canvas, position, size, PLAYER_COLOR);

	t_point top_left;
	top_left.x = position.x - position.x % MINIMAP_CELL_SIZE
	- MINIMAP_CELL_SIZE * MINIMAP_VIEW_RADIUS;
	top_left.y = position.y - position.y % MINIMAP_CELL_SIZE
	- MINIMAP_CELL_SIZE * MINIMAP_VIEW_RADIUS;

	t_point minimap_pos;

	minimap_pos.x = position.x - top_left.x;
	minimap_pos.y = position.y - top_left.y;

	minimap_pos.x += size.width / 2;
	minimap_pos.y += size.height / 2;

	draw_rectangle(canvas, minimap_pos, size, PLAYER_COLOR);
}


void	draw_rays(t_canvas *canvas, t_camera *camera)
{
	t_fpoint	hit;
	t_point		camera_pos;
	t_point		wall;
	int			i;

	camera_pos = scale_position(camera->position);
	i = -1;
	while (++i < camera->rays_count)
	{
		hit = camera->rays[i].position;
		wall = scale_position(hit);
		draw_line(canvas, camera_pos, wall, RAY_COLOR);
	}
}

static t_point	scale_position(t_fpoint position)
{
	t_point	scaled_position;

	scaled_position.x = position.x * MINIMAP_CELL_SIZE / CELL_SIZE;
	scaled_position.y = position.y * MINIMAP_CELL_SIZE / CELL_SIZE;
	return (scaled_position);
}

/*
      mini_pos           pos
------------------ =  ----------
   MINI_CELL_SIZE      CELL_SIZE
*/
