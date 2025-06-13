/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:08:34 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/11 14:07:36 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animations_manager.h"

static void		switch_frame(t_animation *a);
static void		update_texture(t_texture **texture_ref, t_animation *animation);
static t_frame	*get_current_frame(t_animation *animation);

void	update_animations(t_animations *animations)
{
	if (!animations)
		return ;
	switch_frame(animations->north_wall);
	switch_frame(animations->south_wall);
	switch_frame(animations->west_wall);
	switch_frame(animations->east_wall);
	switch_frame(animations->sprite);
}

static void	switch_frame(t_animation *a)
{
	double	now;

	if (a->done || a->delay <= 0.0)
		return ;
	now = mlx_get_time();
	if (now - a->last_time >= a->delay)
	{
		if (a->loop)
			a->current = (a->current + 1) % a->frames_count;
		else if (a->current < a->frames_count - 1)
			a->current++;
		else
			a->done = true;
		a->last_time = now;
	}
}

void	update_textures(t_textures *textures, t_animations *animations)
{
	t_animation	*animation;

	if (!textures || !animations)
		return ;
	animation = animations->north_wall;
	update_texture(&textures->north_wall->texture, animation);
	animation = animations->south_wall;
	update_texture(&textures->south_wall->texture, animation);
	animation = animations->west_wall;
	update_texture(&textures->west_wall->texture, animation);
	animation = animations->east_wall;
	update_texture(&textures->east_wall->texture, animation);
	animation = animations->sprite;
	update_texture(&textures->npc_sprite->texture, animation);
}

static void	update_texture(t_texture **texture_ref, t_animation *animation)
{
	*texture_ref = (t_texture *)get_current_frame(animation);
}

static t_frame	*get_current_frame(t_animation *animation)
{
	t_frame	*current_frame;

	current_frame = animation->frames[animation->current];
	return (current_frame);
}
