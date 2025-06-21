/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 12:26:36 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/21 12:41:40 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprites_drawing.h"

static void	formula_1(t_draw_sprite_data *d);
static void	formula_2(t_draw_sprite_data *d);
static void	formula_3(t_draw_sprite_data *d);
static void	formula_4(t_draw_sprite_data *d);
bool		behind_the_camera(t_draw_sprite_data *d);
bool		out_of_screen(t_draw_sprite_data *d);
void		clamp_draw_bounds(t_draw_sprite_data *d);
void		clamp_ray_bounds(t_draw_sprite_data *d);
bool		outside_field_of_view(t_draw_sprite_data *d);
void		fill_sprite_strip_data(t_draw_sprite_data *d);
void		draw_strips(t_draw_sprite_data *d);

void	draw_sprite(t_canvas *canvas, t_camera *camera, t_npc npc,
	t_sprite *sprite)
{
	t_draw_sprite_data	data;

	data = (t_draw_sprite_data){0};
	data.camera = camera;
	data.canvas = canvas;
	data.npc = npc;
	data.texture = sprite->texture;
	formula_1(&data);
	if (behind_the_camera(&data))
		return ;
	formula_2(&data);
	if (out_of_screen(&data))
	{
		return ;
	}
	formula_3(&data);
	clamp_draw_bounds(&data);
	formula_4(&data);
	clamp_ray_bounds(&data);
	if (outside_field_of_view(&data))
		return ;
	fill_sprite_strip_data(&data);
	draw_strips(&data);
}

//FORMULA 1: DEPTH, HORIZONTAL OFFSET, VERTICAL OFFSET (in the game world)
static void	formula_1(t_draw_sprite_data *d)
{
	d->dx = d->npc.x - d->camera->position.x;
	d->dy = d->npc.y - d->camera->position.y;
	d->cosine = cos(-d->camera->angle);
	d->sine = -sin(-d->camera->angle);
	d->new_x = d->dx * d->cosine - d->dy * d->sine;
	d->new_y = d->dx * d->sine + d->dy * d->cosine;
	d->depth = d->new_x;
	d->horizontal_offset = d->new_y;
	d->vertical_offset = -(d->npc.z - (CELL_SIZE / 2));
}

//FORMULA 2: POSITION ON THE SCREEN (projection from 3d into 2d)
static void	formula_2(t_draw_sprite_data *d)
{
	d->distance_to_the_projection_plane = 1 / tan(d->camera->fov / 2);
	d->projection_plane_x = d->horizontal_offset / d->depth
		* d->distance_to_the_projection_plane;
	d->screen_x = ((double)GAME_SCREEN_WIDTH / PROJECTION_PLANE_WIDTH)
		* d->projection_plane_x + (GAME_SCREEN_WIDTH / 2.0);
	d->projection_plane_y = d->vertical_offset / d->depth
		* d->distance_to_the_projection_plane;
	d->projection_plane_height = (double)GAME_SCREEN_HEIGHT / GAME_SCREEN_WIDTH
		* PROJECTION_PLANE_WIDTH;
	d->screen_y = d->projection_plane_y / d->projection_plane_height
		* GAME_SCREEN_HEIGHT + (GAME_SCREEN_HEIGHT / 2.0);
}

//FORMULA 3: SIZE (SCALING DEPENDING ON DISTANCE)
static void	formula_3(t_draw_sprite_data *d)
{
	d->distance_to_the_screen = d->distance_to_the_projection_plane
		/ PROJECTION_PLANE_WIDTH * GAME_SCREEN_WIDTH;
	d->sprite_screen_width = SPRITE_WIDTH / d->depth
		* d->distance_to_the_screen;
	d->sprite_screen_height = SPRITE_HEIGHT / d->depth
		* d->distance_to_the_screen;
	d->sprite_left = d->screen_x - d->sprite_screen_width / 2;
	d->sprite_right = d->screen_x + d->sprite_screen_width / 2;
	d->sprite_top = d->screen_y - d->sprite_screen_height / 2;
	d->sprite_bottom = d->screen_y + d->sprite_screen_height / 2;
}

//FORMULA 4: WALL OCCLUSION
static void	formula_4(t_draw_sprite_data *d)
{
	d->sprite_angular_width = 2.0 * atan((SPRITE_WIDTH / 2.0) / d->depth);
	d->sprite_center_angle = atan(d->horizontal_offset / d->depth)
		+ d->camera->fov / 2.0;
	d->sprite_left_angle = d->sprite_center_angle
		- d->sprite_angular_width / 2.0;
	d->sprite_right_angle = d->sprite_center_angle
		+ d->sprite_angular_width / 2.0;
	d->degrees_per_ray = d->camera->fov / RAYS_COUNT;
	d->left_ray_index = d->sprite_left_angle / d->degrees_per_ray;
	d->right_ray_index = d->sprite_right_angle / d->degrees_per_ray;
}

// /*
// Links to formulas:
// ---------------------------FORMULA 1----------------------------
// https://chatgpt.com/c/684ac254-4f90-8008-b8c4-4635559146da

// 1) Get the distance vector (distance between camera and object):

// 	(dx, dy) = ((ax - bx), (ay - by))

// 2) Rotate the vector around camera, so that it looks at 0 degrees.
// The standard 2D rotation formula is:

// 	x' = x * cos(θ) - y * sin(θ)
// 	y' = x * sin(θ) + y * cos(θ)

// where x' and y' are the new coordinates after
// rotating point (x, y) by θ degrees

// θ (Theta) - not zero

// ---------------------------FORMULA 2----------------------------
// https://www.canva.com/design/DAGpf-RuHaE/telH_66Y4qNnFQJEAoFxhg/edit

// ---------------------------FORMULA 3----------------------------
// https://claude.ai/chat/fa9cb049-43a8-4086-b298-96ecd2a1dd7e

// The math behind scaling is based on perspective projection 
// and here is the formula:
// object_screen_height = 
// (object_world_height * projection_distance) / object_world_distance
// Where:

// object_world_height = actual height of the object in world units
// projection_distance = distance from camera to the projection plane
// object_world_distance = distance from camera to the object
// object_screen_height = height to draw on screen in pixels
// */
