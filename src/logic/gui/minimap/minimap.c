/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:11:37 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/16 17:42:45 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

static void		draw_map(mlx_image_t *screen, t_map *map);
void		draw_player(mlx_image_t *screen, int x, int y);
void		draw_rectangle(mlx_image_t *screen, int x, int y, int width, int height,  t_color color);

void	draw_minimap(mlx_image_t *screen, t_game *game)
{
	t_point player_position;

	player_position = game->player_position;
	draw_map(screen, game->map);
	draw_player(screen, player_position.x, player_position.y);
}

static void draw_map(mlx_image_t* screen, t_map* map)
{
	int	x;
	int	y;
	
	int cell_size = 64;
	t_color colorWhite = get_color(255, 255, 255, 255);
	t_color colorRed = get_color(255, 0, 0, 255);
	t_color colorGreen = get_color(0, 255, 0, 255);
	t_color color;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->cells[y][x] == '0')
				color = colorWhite;
			else if (map->cells[y][x] == '1')
				color = colorRed;
			else
				color = colorGreen;
			draw_rectangle(screen,
				x * cell_size, y * cell_size,
				cell_size - 1, cell_size - 1,
				color);
		}
	}
}

void	draw_player(mlx_image_t* screen, int x, int y)
{
	t_color color = get_color(0, 255, 0, 255);

	draw_rectangle(screen, x, y, 10, 10, color);
}

void	draw_rectangle(mlx_image_t *screen, int x, int y, int width, int height,  t_color color)
{
	int	i;
	int	j;
	int width_copy;
	
	width_copy = width;
	j = y;
	while (height--)
	{
		width = width_copy;
		i = x;
		while (width--)
		{
			mlx_put_pixel(screen, i, j, color);
			i++;
		}
		j++;
	}
}
