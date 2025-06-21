/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_drawing_helpers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 12:31:07 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/21 12:41:16 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprites_drawing.h"

bool	out_of_screen(t_draw_sprite_data *d)
{
	if (d->sprite_right < 0)
		return (true);
	if (d->sprite_left >= GAME_SCREEN_WIDTH)
		return (true);
	if (d->sprite_bottom < 0)
		return (true);
	if (d->sprite_top >= GAME_SCREEN_HEIGHT)
		return (true);
	return (false);
}

void	clamp_draw_bounds(t_draw_sprite_data *d)
{
	d->draw_left = d->sprite_left;
	if (d->draw_left < 0)
		d->draw_left = 0;
	d->draw_right = d->sprite_right;
	if (d->draw_right >= GAME_SCREEN_WIDTH)
		d->draw_right = GAME_SCREEN_WIDTH - 1;
	d->draw_top = d->sprite_top;
	if (d->draw_top < 0)
		d->draw_top = 0;
	d->draw_bottom = d->sprite_bottom;
	if (d->draw_bottom >= GAME_SCREEN_HEIGHT)
		d->draw_bottom = GAME_SCREEN_HEIGHT - 1;
}

void	clamp_ray_bounds(t_draw_sprite_data *d)
{
	if (d->left_ray_index < 0)
		d->left_ray_index = 0;
	if (d->right_ray_index >= RAYS_COUNT)
		d->right_ray_index = RAYS_COUNT - 1;
	d->total_strips = d->right_ray_index - d->left_ray_index + 1;
}

bool	outside_field_of_view(t_draw_sprite_data *d)
{
	if (d->left_ray_index >= RAYS_COUNT || d->right_ray_index < 0)
		return (true);
	if (d->total_strips < 1)
		return (true);
	return (false);
}

void	fill_sprite_strip_data(t_draw_sprite_data *d)
{
	d->strip_width = (d->draw_right - d->draw_left + 1)
		/ (double)d->total_strips;
	d->strip_height = d->draw_bottom - d->draw_top + 1;
	d->texture_x_step = (double)d->texture->width / d->sprite_screen_width;
	d->texture_y_step = (double)d->texture->height / d->sprite_screen_height;
}
