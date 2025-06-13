/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:09:49 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/13 17:13:24 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprites.h"

void	draw_sprites(t_canvas *canvas, t_camera *camera, t_game *game,
	t_textures *textures)
{
	t_sprite	*sprite;
	int	i;

	sprite = textures->npc_sprite;
	i = -1;
	while (++i < game->npc_count)
		draw_sprite(canvas, camera, game->npcs[i], sprite);
}

// 3d projection matrix - no idea how it works :(
void	draw_sprite(t_canvas *canvas, t_camera *camera, t_npc npc, t_sprite *sprite)
{
	(void)sprite;

	// Formula 1
	double dx = npc.x - camera->position.x;
	double dy = npc.y - camera->position.y;

	// Formula 2 preparations
	double cosine = cos(-camera->angle);
	double sine = -sin(-camera->angle);

	// Formula 2
	double new_x = dx * cosine - dy * sine;
	double new_y = dx * sine + dy * cosine;

	// Computer mathematic errors fix
	if (is_almost_zero(new_x))
		new_x = 0;
	if (is_almost_zero(new_y))
		new_y = 0;

	double depth = new_x;
	double horizontal_offset = new_y;
	double vertical_offset = npc.z - CELL_SIZE / 2;

	// If depth is bigger than 1, it means that the object is in front of us
	// and we need to draw it
	if (depth > 1)
	{
		// Formula 3
		// projection_factor or "distance to the projection plane"
		double projection_factor = (GAME_SCREEN_WIDTH / 2) / tan(camera->fov / 2);

		// Formula 4 (which I don't get yet)
		double screen_x = (horizontal_offset * projection_factor / depth)
				+ (GAME_SCREEN_WIDTH / 2);
		double screen_y = (vertical_offset * projection_factor / depth)
				+ (GAME_SCREEN_HEIGHT / 2);

		if (screen_x < 0 || screen_y < 0
		|| screen_x > GAME_SCREEN_WIDTH
		|| screen_y > GAME_SCREEN_HEIGHT)
			return ;
		
		draw_rectangle(canvas, (t_point){screen_x, screen_y}, (t_size){10, 10}, 0x00ffffff);
		// draw_pixel(canvas, screen_x, screen_y, 0x00ffffff);
	}
}

/*
11111
10X01
10S01
11111
*/

// Formula number 1
// Get the distance vector:
// (dx, dy) = ((ax - bx), (ay - by))

// Formula number 2
/*
The standard 2D rotation formula is:

x' = x * cos(θ) - y * sin(θ)
y' = x * sin(θ) + y * cos(θ)

where x' and y' are the new coordinates after
rotating point (x, y) by θ degrees

θ (Theta) - not zero
*/

// Formula number 3
/*
                                screen_width/2
distance to projection plane = ----------------
                                  tan(FOV/2)
*/




















// void drawSprite(t_canvas *canvas, t_camera *camera, t_npc *npc)
// {
// 	int x, y, s;

// 	for (s = 0; s < 4; s++)
// 	{
// 		float sx = npc->x - camera->position.x; // temp float variables
// 		float sy = npc->y - camera->position.y;
// 		float sz = npc->z;

// 		float CS = cos(camera->angle),
// 			  SN = sin(camera->angle); // rotate around origin
// 		float a = sy * CS + sx * SN;
// 		float b = sx * CS - sy * SN;
// 		sx = a;
// 		sy = b;

// 		sx = (sx * 108.0 / sy) + (GAME_SCREEN_WIDTH / 2); // convert to screen x,y
// 		sy = (sz * 108.0 / sy) + (GAME_SCREEN_HEIGHT / 2);

// 		int scale = 32 * 80 / b; // scale sprite based on distance
// 		if (scale < 0)
// 		{
// 			scale = 0;
// 		}
// 		if (scale > 120)
// 		{
// 			scale = 120;
// 		}

// 		// texture
// 		float t_x = 0, t_y = 31, t_x_step = 31.5 / (float)scale,
// 			  t_y_step = 32.0 / (float)scale;

// 		for (x = sx - scale / 2; x < sx + scale / 2; x++)
// 		{
// 			t_y = 31;
// 			for (y = 0; y < scale; y++)
// 			{
// 				if (sp[s].state == 1 && x > 0 && x < 120 && b < depth[x])
// 				{
// 					int pixel = ((int)t_y * 32 + (int)t_x) * 3 +
// 								(sp[s].map * 32 * 32 * 3);
// 					int red = sprites[pixel + 0];
// 					int green = sprites[pixel + 1];
// 					int blue = sprites[pixel + 2];
// 					if (red != 255, green != 0,
// 						blue != 255) // dont draw if purple
// 					{
// 						glPointSize(8);
// 						glColor3ub(red, green, blue);
// 						glBegin(GL_POINTS);
// 						glVertex2i(x * 8, sy * 8 - y * 8);
// 						glEnd(); // draw point
// 					}
// 					t_y -= t_y_step;
// 					if (t_y < 0)
// 					{
// 						t_y = 0;
// 					}
// 				}
// 			}
// 			t_x += t_x_step;
// 		}
// 	}
// }
