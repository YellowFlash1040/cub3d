/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_drawing.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:09:31 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/21 12:27:06 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_DRAWING_H
# define SPRITES_DRAWING_H

# include "settings.h"
# include "canvas.h"
# include "drawing.h"
# include "camera.h"
# include "game.h"
# include "textures.h"
# include "geometry.h"

# define PROJECTION_PLANE_WIDTH 2

typedef struct draw_sprite_data
{
	t_camera	*camera;
	t_canvas	*canvas;
	t_npc		npc;
	t_texture	*texture;
	double		dx;
	double		dy;
	double		cosine;
	double		sine;
	double		new_x;
	double		new_y;
	double		depth;
	double		horizontal_offset;
	double		vertical_offset;
	double		distance_to_the_projection_plane;
	double		projection_plane_x;
	double		screen_x;
	double		projection_plane_y;
	double		projection_plane_height;
	double		screen_y;
	double		distance_to_the_screen;
	double		sprite_screen_width;
	double		sprite_screen_height;
	double		sprite_left;
	double		sprite_right;
	double		sprite_top;
	double		sprite_bottom;
	int			draw_left;
	int			draw_right;
	int			draw_top;
	int			draw_bottom;
	double		sprite_angular_width;
	double		sprite_center_angle;
	double		sprite_left_angle;
	double		sprite_right_angle;
	double		degrees_per_ray;
	int			left_ray_index;
	int			right_ray_index;
	int			total_strips;
	double		strip_width;
	int			strip_height;
	int			ray_index;
	int			strip_left;
	int			strip_right;
	t_point		draw_point;
	t_size		strip_size;
	t_point		sprite_position;
	double		texture_x_step;
	double		texture_y_step;
}	t_draw_sprite_data;

void	draw_sprites(t_canvas *canvas, t_camera *camera, t_game *game,
			t_textures *textures);
void	draw_sprite(t_canvas *canvas, t_camera *camera, t_npc npc,
			t_sprite *sprite);

#endif
