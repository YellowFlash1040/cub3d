/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:11:37 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/21 13:39:26 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

static void	draw_map(t_canvas *canvas, t_map* map);
static void	draw_player(t_canvas *canvas, t_player *player);
// static void	draw_player_direction(t_canvas *canvas, t_player *player);

void	draw_minimap(t_canvas *canvas, t_game *game)
{
	t_player	*player;
	t_map		*map;

	player = game->player;
	map = game->map;

	draw_map(canvas, map);
	draw_player(canvas, player);

	t_point player_pos = (t_point){player->position.x, player->position.y};
	t_point wall;

	// t_fpoint horizontal_hit = find_horizontal_hit(player, map);
	// wall = (t_point){horizontal_hit.x, horizontal_hit.y};
	// draw_line(canvas, player_pos, wall, 0xff0000ff);

	// t_fpoint vertical_hit = find_vertical_hit(player, map);
	// wall = (t_point){vertical_hit.x, vertical_hit.y};
	// draw_line(canvas, player_pos, wall, 0x00ff00ff);

	t_fpoint hit = find_ray_hit(player, map);
	wall = (t_point){hit.x, hit.y};
	draw_line(canvas, player_pos, wall, 0x00ffffff);
}

static void draw_map(t_canvas *canvas, t_map* map)
{
	int	x;
	int	y;
	
	int cell_size = 64;
	t_color colorWhite = get_color(255, 255, 255, 255);
	t_color colorRed = get_color(255, 0, 0, 255);
	t_color colorGreen = get_color(0, 255, 0, 255);
	t_color colorBlack = get_color(0, 0, 0, 255);
	t_color color;

	(void)colorWhite;
	(void)colorRed;
	(void)colorGreen;
	(void)colorBlack;
	(void)color;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->cells[y][x] == '0')
				color = colorBlack;
			else if (map->cells[y][x] == '1')
				color = colorWhite;
			else
				color = colorGreen;
			draw_rectangle(canvas,
				(t_point){x * cell_size, y * cell_size},
				(t_size){cell_size - 1, cell_size - 1},
				color);
		}
	}
}

static void	draw_player(t_canvas *canvas, t_player *player)
{
	draw_rectangle(canvas, (t_point){player->position.x, player->position.y}, (t_size){10, 10},
		(t_color)0xffff00ff);
}

// static void draw_player_direction(t_canvas *canvas, t_player *player)
// {
// 	t_point ray_end;

// 	ray_end.x = player->position.x + player->delta_x * 5;
// 	ray_end.y = player->position.y + player->delta_y * 5;
// 	t_point player_pos = (t_point){player->position.x, player->position.y};
// 	draw_line(canvas, player_pos, ray_end, (t_color)0xffff00ff);
// }
