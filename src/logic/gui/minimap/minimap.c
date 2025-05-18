/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:11:37 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/18 15:51:07 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

static void	draw_map(t_canvas *canvas, t_map* map);
static void	draw_player(t_canvas *canvas, t_point player_position);

void	draw_minimap(t_canvas *canvas, t_game *game)
{
	draw_map(canvas, game->map);
	draw_player(canvas, game->player->position);
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

static void	draw_player(t_canvas *canvas, t_point player_position)
{
	draw_rectangle(canvas, player_position, (t_size){10, 10},
		(t_color)0xffff00ff);
}
