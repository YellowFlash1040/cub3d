/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_drawing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:09:49 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/18 14:21:08 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprites_drawing.h"

void draw_sprite2(t_canvas *canvas, t_camera *camera, t_npc npc, t_sprite *sprite);
void draw_sprite3(t_canvas *canvas, t_camera *camera, t_npc npc, t_sprite *sprite);

void	draw_sprites(t_canvas *canvas, t_camera *camera, t_game *game,
	t_textures *textures)
{
	t_sprite	*sprite;
	int	i;

	sprite = textures->npc_sprite;
	i = -1;
	while (++i < game->npc_count)
	{
		//AI Function
		draw_sprite2(canvas, camera, game->npcs[i], sprite);
		//Function, which is 80% mine, and works fine
		draw_sprite3(canvas, camera, game->npcs[i], sprite);
		//My function, which is not perfect
		draw_sprite(canvas, camera, game->npcs[i], sprite);
	}
}

void	draw_sprite3(t_canvas *canvas, t_camera *camera, t_npc npc, t_sprite *sprite)
{
	(void)sprite;

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
	
	/*--------------------NOT NOT NOT MY PART (OK, now it is my code, but it has to become DRY)-----------------------------*/
	// Calculate sprite bounds on screen
    double sprite_left = screen_x - sprite_screen_width / 2;
    double sprite_right = screen_x + sprite_screen_width / 2;
    double sprite_top = screen_y - sprite_screen_height / 2;
    double sprite_bottom = screen_y + sprite_screen_height / 2;

    // Early culling - if completely off screen
    if (sprite_right < 0 || sprite_left >= GAME_SCREEN_WIDTH || 
        sprite_bottom < 0 || sprite_top >= GAME_SCREEN_HEIGHT)
	{
        return ;
	}

    // Clamp sprite bounds to screen
    // int draw_left = (int)fmax(0, sprite_left);
    // int draw_right = (int)fmin(GAME_SCREEN_WIDTH - 1, sprite_right);
    // int draw_top = (int)fmax(0, sprite_top);
    // int draw_bottom = (int)fmin(GAME_SCREEN_HEIGHT - 1, sprite_bottom);
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
	/*--------------------NOT NOT NOT MY PART-----------------------------*/

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
	/*------------------------------------------------*/
    
    // For partial rendering, we'll divide the sprite into strips
    double strip_width = (draw_right - draw_left + 1) / (double)total_strips;
	int strip_height = draw_bottom - draw_top;
    
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
            draw_rectangle(canvas, draw_point, strip_size, 0xffff00ff);
        }
    }
}

void	draw_sprite(t_canvas *canvas, t_camera *camera, t_npc npc, t_sprite *sprite)
{
	(void)sprite;

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

	t_point top_left;
	top_left.x = screen_x - (sprite_screen_width / 2);
	top_left.y = screen_y - (sprite_screen_height / 2);
	// t_size size = (t_size){sprite_screen_width, sprite_screen_height};

	if (screen_x + (sprite_screen_width / 2) < 0
	|| screen_x - (sprite_screen_width / 2) >= GAME_SCREEN_WIDTH
	|| screen_y + (sprite_screen_height / 2) < 0
	|| screen_y - (sprite_screen_height / 2) >= GAME_SCREEN_HEIGHT)
		return ;

	//------------FORMULA 4: WALL OCCLUSION--------------------------------------
	double sprite_angle_width = 2.0 * atan((SPRITE_SIZE / 2) / depth); 

	double sprite_angle_center = atan(horizontal_offset / depth) + (camera->fov / 2.0);
	double sprite_angle_left_side = sprite_angle_center - sprite_angle_width / 2;
	double sprite_angle_right_side = sprite_angle_center + sprite_angle_width / 2;

	double angle_per_ray = camera->fov / RAYS_COUNT;

	int left_ray_index = sprite_angle_left_side  / angle_per_ray;
	int right_ray_index = sprite_angle_right_side / angle_per_ray;

	if (right_ray_index < 0 || left_ray_index >= RAYS_COUNT)
		return ;

	if (left_ray_index < 0)
		left_ray_index = 0;
	if (right_ray_index >= RAYS_COUNT)
		right_ray_index = RAYS_COUNT - 1;

	int total_rays_count = right_ray_index - left_ray_index + 1;

	if (total_rays_count < 1)
    	return ;

	int strip_width = sprite_screen_width / total_rays_count;
	for (int i = 0; i < total_rays_count; i++)
	{
		int ray_index = left_ray_index + i;
		if (depth < camera->rays[ray_index].length)
		{
			t_point position;
			position.x = top_left.x + strip_width * i;
			position.y = top_left.y;
			t_size strip_size;
			strip_size.width = strip_width;
			strip_size.height = sprite_screen_height;
			draw_rectangle(canvas, position, strip_size, 0x00ff00ff);
		}
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



// -----------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------

void draw_sprite2(t_canvas *canvas, t_camera *camera, t_npc npc, t_sprite *sprite)
{
    (void)sprite;

    // Formula 1 - world space offset from camera
    double dx = npc.x - camera->position.x;
    double dy = npc.y - camera->position.y;

    // Formula 2 preparations
    double cosine = cos(-camera->angle);
    double sine = -sin(-camera->angle);

    // Formula 2 - rotate to camera space
    double new_x = dx * cosine - dy * sine;
    double new_y = dx * sine + dy * cosine;

    // Fix float number precision errors
    if (is_almost_zero(new_x))
        new_x = 0;
    if (is_almost_zero(new_y))
        new_y = 0;

    double depth = new_x;
    double horizontal_offset = new_y;
    // double vertical_offset = npc.z - CELL_SIZE / 2;
    double vertical_offset = -npc.z + CELL_SIZE / 2;

    // If depth is not positive enough, sprite is behind or too close
    if (depth <= 1)
        return ;

    // Formula 3 - projection factor
    double horizontal_projection_factor = 1 / tan(camera->fov / 2);
    double vertical_projection_factor = ((double)GAME_SCREEN_WIDTH / GAME_SCREEN_HEIGHT) / tan(camera->fov / 2);

    // Calculate sprite size based on distance (distance scaling)
    double sprite_screen_width = (SPRITE_SIZE * horizontal_projection_factor) / depth * (GAME_SCREEN_WIDTH / 2);
    double sprite_screen_height = (SPRITE_SIZE * vertical_projection_factor) / depth * (GAME_SCREEN_HEIGHT / 2);
    
    // Skip if sprite would be too small to see
    if (sprite_screen_width < 1 || sprite_screen_height < 1)
        return ;

    // Formula 4 - project to screen coordinates
    double screen_x = (horizontal_offset * horizontal_projection_factor / depth) * (GAME_SCREEN_WIDTH / 2) + (GAME_SCREEN_WIDTH / 2);
    double screen_y = (vertical_offset * vertical_projection_factor / depth) * (GAME_SCREEN_HEIGHT / 2) + (GAME_SCREEN_HEIGHT / 2);

    // Calculate sprite bounds on screen
    double sprite_left = screen_x - sprite_screen_width / 2;
    double sprite_right = screen_x + sprite_screen_width / 2;
    double sprite_top = screen_y - sprite_screen_height / 2;
    double sprite_bottom = screen_y + sprite_screen_height / 2;

    // Early culling - if completely off screen
    if (sprite_right < 0 || sprite_left >= GAME_SCREEN_WIDTH || 
        sprite_bottom < 0 || sprite_top >= GAME_SCREEN_HEIGHT)
        return ;

    // Clamp sprite bounds to screen
    int draw_left = (int)fmax(0, sprite_left);
    int draw_right = (int)fmin(GAME_SCREEN_WIDTH - 1, sprite_right);
    int draw_top = (int)fmax(0, sprite_top);
    int draw_bottom = (int)fmin(GAME_SCREEN_HEIGHT - 1, sprite_bottom);

    // Calculate which rays we need to check for occlusion (преграждение)
    // Each ray covers (CAMERA_FIELD_OF_VIEW / RAYS_COUNT) degrees
    double degrees_per_ray = CAMERA_FIELD_OF_VIEW / (double)RAYS_COUNT;
    
    // Calculate the angular extent of the sprite
    double sprite_half_width_world = SPRITE_SIZE / 2.0;
    double sprite_angular_width = 2.0 * atan(sprite_half_width_world / depth) * (180.0 / M_PI);
    
    // Find the range of rays that intersect with the sprite
    double sprite_center_angle = atan(horizontal_offset / depth) * (180.0 / M_PI);
    double sprite_left_angle = sprite_center_angle - sprite_angular_width / 2.0;
    double sprite_right_angle = sprite_center_angle + sprite_angular_width / 2.0;
    
    // Convert angles to ray indices (rays go from -30 to +30 degrees)
    int left_ray_index = (int)((sprite_left_angle + CAMERA_FIELD_OF_VIEW/2.0) / degrees_per_ray);
    int right_ray_index = (int)((sprite_right_angle + CAMERA_FIELD_OF_VIEW/2.0) / degrees_per_ray);
    
    // Clamp ray indices to valid range
    left_ray_index = fmax(0, fmin(RAYS_COUNT - 1, left_ray_index));
    right_ray_index = fmax(0, fmin(RAYS_COUNT - 1, right_ray_index));

    // Check for partial occlusion
    // We'll draw the sprite in vertical strips, checking each strip against corresponding rays
    int visible_strips = 0;
    int total_strips = right_ray_index - left_ray_index + 1;
    
    if (total_strips <= 0)
        total_strips = 1; // At least check one ray for very thin sprites
    
    // For partial rendering, we'll divide the sprite into strips
    double strip_width = (draw_right - draw_left + 1) / (double)total_strips;
    
    for (int i = 0; i < total_strips; i++)
    {
        int ray_index = left_ray_index + i;
        if (ray_index < 0) ray_index = 0;
        if (ray_index >= RAYS_COUNT) ray_index = RAYS_COUNT - 1;
        
        // Check if this strip is visible (not occluded by walls)
        if (depth < camera->rays[ray_index].length)
        {
            // This strip is visible, calculate its screen bounds
            int strip_left = draw_left + (int)(i * strip_width);
            int strip_right = draw_left + (int)((i + 1) * strip_width);
            
            // Clamp strip bounds
            strip_left = fmax(draw_left, strip_left);
            strip_right = fmin(draw_right, strip_right);
            
            // Draw this strip of the sprite
            if (strip_right > strip_left)
            {
                t_point draw_point = {strip_left, draw_top};
                t_size strip_size = {strip_right - strip_left, draw_bottom - draw_top};
                draw_rectangle(canvas, draw_point, strip_size, 0x00ffffff);
                visible_strips++;
            }
        }
    }
}


// -----------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------

// // 3d projection matrix - no idea how it works :(
// void	draw_sprite(t_canvas *canvas, t_camera *camera, t_npc npc, t_sprite *sprite)
// {
// 	(void)sprite;

// 	// Formula 1
// 	double dx = npc.x - camera->position.x;
// 	double dy = npc.y - camera->position.y;

// 	// Formula 2 preparations
// 	double cosine = cos(-camera->angle);
// 	double sine = -sin(-camera->angle);

// 	// Formula 2
// 	double new_x = dx * cosine - dy * sine;
// 	double new_y = dx * sine + dy * cosine;

// 	// Fix float number precision errors
// 	if (is_almost_zero(new_x))
// 		new_x = 0;
// 	if (is_almost_zero(new_y))
// 		new_y = 0;

// 	double depth = new_x;
// 	double horizontal_offset = new_y;
// 	double vertical_offset = npc.z - CELL_SIZE / 2;

// 	// If depth is bigger than 1, it means that the object is in front of us
// 	// and we need to draw it
// 	if (depth > 1)
// 	{
// 		// Formula 3
// 		// projection factor or "distance to the projection plane"
// 		double projection_factor = (GAME_SCREEN_WIDTH / 2) / tan(camera->fov / 2);

// 		// Formula 4 (which I don't get yet)
// 		double screen_x = (horizontal_offset * projection_factor / depth)
// 				+ (GAME_SCREEN_WIDTH / 2);
// 		double screen_y = (vertical_offset * projection_factor / depth)
// 				+ (GAME_SCREEN_HEIGHT / 2);

// 		if (screen_x < 0 || screen_y < 0
// 		|| screen_x > GAME_SCREEN_WIDTH
// 		|| screen_y > GAME_SCREEN_HEIGHT)
// 			return ;

// 		int ray_index = horizontal_offset + RAYS_COUNT / 2;

// 		if (ray_index < 0)
// 			ray_index = 0;
// 		else if (ray_index >= RAYS_COUNT)
// 			ray_index = RAYS_COUNT - 1;

// 		if (depth > camera->rays[ray_index].length)
// 			return ;

// 		t_size sprite_size = (t_size){SPRITE_SIZE, SPRITE_SIZE};
// 		t_point draw_point;
// 		draw_point.x = screen_x - sprite_size.width / 2;
// 		draw_point.y = screen_y - sprite_size.height / 2;
// 		draw_rectangle(canvas, draw_point, sprite_size, 0x00ffffff);
		
// 		// // Define the base size of your sprite in world units
// 		// double base_sprite_size = SPRITE_SIZE;

// 		// // Scale the sprite based on distance using the projection factor
// 		// double sprite_screen_size = (base_sprite_size * projection_factor) / depth;

// 		// // Make sure the sprite doesn't get too small or too large
// 		// if (sprite_screen_size < 1.0)
//    	 	// sprite_screen_size = 1.0;
// 		// else if (sprite_screen_size > 200.0)
//     	// 	sprite_screen_size = 200.0;

// 		// // Calculate the top-left corner to center the sprite
// 		// int start_x = screen_x - sprite_screen_size / 2;
// 		// int start_y = screen_y - sprite_screen_size / 2;

// 		// for (int x = 0; x < sprite_screen_size; x++)
// 		// {
//     	// 	// Calculate ray index once per column
//     	// 	int ray_index = (horizontal_offset + x - sprite_screen_size/2) + RAYS_COUNT / 2;
	
//     	// 	if (ray_index < 0)
//     	// 	    ray_index = 0;
//     	// 	else if (ray_index >= RAYS_COUNT)
//     	// 	    ray_index = RAYS_COUNT - 1;
	
//     	// 	// Check depth once per column
//     	// 	if (depth > camera->rays[ray_index].length)
//     	//   	  continue;
	
//     	// 	for (int y = 0; y < sprite_screen_size; y++)
//     	// 	{
// 		// 		int sx = start_x + x;
// 		// 		int sy = start_y + y;
		
//     	//    	 	// Check bounds
//     	//     	if (sx >= 0 && sy >= 0 && sx < GAME_SCREEN_WIDTH && sy < GAME_SCREEN_HEIGHT)
//     	//     	    draw_pixel(canvas, sx, sy, 0x00ffffff);
//     	// 	}
// 		// }
// 	}
// }



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
