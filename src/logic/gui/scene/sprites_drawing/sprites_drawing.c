/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_drawing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:09:49 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/18 18:01:07 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprites_drawing.h"

void draw_strip(t_canvas *canvas, t_point draw_point, t_point sprite_position, t_size strip_size, t_texture *texture, t_size sprite_size);

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

void	draw_sprite(t_canvas *canvas, t_camera *camera, t_npc npc, t_sprite *sprite)
{
	//----------FORMULA 1: DEPTH, HORIZONTAL OFFSET, VERTICAL OFFSET------------------
	double dx = npc.x - camera->position.x;
	double dy = npc.y - camera->position.y;

	double cosine = cos(-camera->angle);
	double sine = -sin(-camera->angle);

	// x' = x * cos(θ) - y * sin(θ)
	// y' = x * sin(θ) + y * cos(θ)
	double new_x = dx * cosine - dy * sine;
	double new_y = dx * sine + dy * cosine;

	double depth = new_x;
	double horizontal_offset = new_y;
	double vertical_offset = -(npc.z - (CELL_SIZE / 2));

	if (depth < 1)
		return ;

	//-------------FORMULA 2: POSITION (projection from 3d into 2d)------------------
	double distance_to_the_projection_plane = 1 / tan(camera->fov / 2);

	double projection_plane_x = horizontal_offset / depth * distance_to_the_projection_plane;

	double screen_x = ((double)GAME_SCREEN_WIDTH / PROJECTION_PLANE_WIDTH) * projection_plane_x + (GAME_SCREEN_WIDTH / 2.0);

	double projection_plane_y = vertical_offset / depth * distance_to_the_projection_plane;
	
	// double projection_plane_height = tan(camera->fov / 2) * distance_to_the_projection_plane * 2;
	double projection_plane_height = (double)GAME_SCREEN_HEIGHT / GAME_SCREEN_WIDTH * PROJECTION_PLANE_WIDTH;

	double screen_y = projection_plane_y / projection_plane_height * GAME_SCREEN_HEIGHT + (GAME_SCREEN_HEIGHT / 2.0);

	//-------------FORMULA 3: SIZE (SCALING DEPENDING ON DISTANCE)---------------
	double distance_to_the_screen = distance_to_the_projection_plane / PROJECTION_PLANE_WIDTH * GAME_SCREEN_WIDTH;
	double sprite_screen_width = SPRITE_SIZE / depth * distance_to_the_screen;
	double sprite_screen_height = SPRITE_SIZE / depth * distance_to_the_screen;
	
	// Calculate sprite bounds on screen
    double sprite_left = screen_x - sprite_screen_width / 2;
    double sprite_right = screen_x + sprite_screen_width / 2;
    double sprite_top = screen_y - sprite_screen_height / 2;
    double sprite_bottom = screen_y + sprite_screen_height / 2;

    // Early culling - if completely off screen
    if (sprite_right < 0 || sprite_left >= GAME_SCREEN_WIDTH
		|| sprite_bottom < 0 || sprite_top >= GAME_SCREEN_HEIGHT)
	{
        return ;
	}

    // Clamp sprite bounds to screen
	int draw_left = sprite_left;
	if (draw_left < 0)
		draw_left = 0;
	int draw_right = sprite_right;
	if (draw_right >= GAME_SCREEN_WIDTH)
		draw_right = GAME_SCREEN_WIDTH - 1;
	int draw_top = sprite_top;
	if (draw_top < 0)
		draw_top = 0;
	int draw_bottom = sprite_bottom;
	if (draw_bottom >= GAME_SCREEN_HEIGHT)
		draw_bottom = GAME_SCREEN_HEIGHT - 1;

	/*-----------------------WALL OCCLUSION--------------------------*/
    double sprite_angular_width = 2.0 * atan((SPRITE_SIZE / 2.0) / depth);

    double sprite_center_angle = atan(horizontal_offset / depth) + camera->fov / 2.0;
    double sprite_left_angle = sprite_center_angle - sprite_angular_width / 2.0;
    double sprite_right_angle = sprite_center_angle + sprite_angular_width / 2.0;

	double degrees_per_ray = camera->fov / RAYS_COUNT;
	int left_ray_index = sprite_left_angle / degrees_per_ray;
    int right_ray_index = sprite_right_angle / degrees_per_ray;
    
	if (left_ray_index >= RAYS_COUNT || right_ray_index < 0)
		return ;

	if (left_ray_index < 0)
		left_ray_index = 0;
	if (right_ray_index >= RAYS_COUNT)
		right_ray_index = RAYS_COUNT - 1;

    int total_strips = right_ray_index - left_ray_index + 1;
    
	if (total_strips < 1)
        return ;
    
    // For partial rendering, we'll divide the sprite into strips
    double strip_width = (draw_right - draw_left + 1) / (double)total_strips;
	int strip_height = draw_bottom - draw_top + 1;
    
    for (int i = 0; i < total_strips; i++)
    {
        int ray_index = left_ray_index + i;
        
        // Check if this strip is visible (not occluded by walls)
        if (depth < camera->rays[ray_index].length)
        {
            // Calculate strip bounds
			int strip_left = draw_left + (strip_width * i);
            int strip_right = draw_left + (strip_width * (i + 1));
            
            t_point draw_point = {strip_left, draw_top};
            t_size strip_size = {strip_right - strip_left, strip_height};

			t_point sprite_position;
			sprite_position.x = strip_left - (screen_x - sprite_screen_width / 2);
			sprite_position.y = draw_top - (screen_y - sprite_screen_height / 2);

			draw_strip(canvas, draw_point, sprite_position, strip_size, sprite->texture, (t_size){sprite_screen_width, sprite_screen_height});
        }
    }
}

void draw_strip(t_canvas *canvas, t_point draw_point, t_point sprite_position, t_size strip_size, t_texture *texture, t_size sprite_size)
{
	double texture_x;
	double texture_y;

	double texture_x_step = (double)texture->width / sprite_size.width;
	double texture_y_step = (double)texture->height / sprite_size.height;

	texture_y = sprite_position.y * texture_y_step;
	for (int y = 0; y < strip_size.height; y++)
	{
		texture_x = sprite_position.x * texture_x_step;
		for (int x = 0; x < strip_size.width; x++)
		{
			t_color pixel = get_texture_pixel(texture, texture_x, texture_y);
			// Skip transparent pixels
			if (pixel != 0x000000) // RGB(0,0,0)
			    draw_pixel(canvas, draw_point.x + x, draw_point.y + y, pixel);
			texture_x += texture_x_step;
			if (texture_x >= texture->width)
				texture_x = texture->width - 1;
		}
		texture_y += texture_y_step;
		if (texture_y >= texture->height)
			texture_y = texture->height - 1;
	}
}

/*
Links to formulas:
---------------------------FORMULA 1----------------------------
https://chatgpt.com/c/684ac254-4f90-8008-b8c4-4635559146da

1) Get the distance vector (distance between camera and object):

	(dx, dy) = ((ax - bx), (ay - by))

2) Rotate the vector around camera, so that it looks at 0 degrees.
The standard 2D rotation formula is:

	x' = x * cos(θ) - y * sin(θ)
	y' = x * sin(θ) + y * cos(θ)

where x' and y' are the new coordinates after
rotating point (x, y) by θ degrees

θ (Theta) - not zero

---------------------------FORMULA 2----------------------------
https://www.canva.com/design/DAGpf-RuHaE/telH_66Y4qNnFQJEAoFxhg/edit

---------------------------FORMULA 3----------------------------
https://claude.ai/chat/fa9cb049-43a8-4086-b298-96ecd2a1dd7e

The math behind scaling is based on perspective projection and here is the formula:
object_screen_height = (object_world_height * projection_distance) / object_world_distance
Where:

object_world_height = actual height of the object in world units
projection_distance = distance from camera to the projection plane
object_world_distance = distance from camera to the object
object_screen_height = height to draw on screen in pixels
*/
