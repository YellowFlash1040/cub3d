/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:18:22 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/11 12:05:37 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animation.h"

t_animation	*init_animation(void)
{
	t_animation	*animation;

	animation = (t_animation *)malloc(sizeof(t_animation));
	if (!animation)
		return (NULL);
	animation->frames = NULL;
	animation->frames_count = 0;
	animation->delay = 0;
	animation->loop = false;
	animation->done = false;
	animation->current = 0;
	animation->last_time = 0.0;
	return (animation);
}

void	destroy_animation(t_animation **animation_ref)
{
	t_animation	*animation;

	if (!animation_ref || !*animation_ref)
		return ;
	animation = *animation_ref;
	if (animation->frames)
		destroy_frames(&animation->frames);
	free(animation);
	*animation_ref = NULL;
}

void	destroy_frames(t_frame ***frames_ref)
{
	t_frame	**frames;
	int		i;

	if (!frames_ref || !*frames_ref)
		return ;
	frames = *frames_ref;
	i = -1;
	while (frames[++i])
		destroy_frame(&frames[i]);
	free(frames);
	*frames_ref = NULL;
}

int	build_animation(t_animation **animation_ref, int frames_count)
{
	t_animation	*animation;

	if (!animation_ref || !*animation_ref)
		return (EMPTY_PTR_ERR);
	animation = *animation_ref;
	animation->frames = (t_frame **)malloc(sizeof(t_frame *)
			* (frames_count + 1));
	if (!animation->frames)
		return (destroy_animation(animation_ref), MALLOC_FAIL_ERR);
	animation->frames[frames_count] = NULL;
	animation->frames_count = frames_count;
	return (SUCCESS);
}

t_animation	*create_animation(int frames_count, double delay, bool loop)
{
	t_animation	*animation;
	int			result;

	animation = init_animation();
	if (!animation)
		return (NULL);
	result = build_animation(&animation, frames_count);
	if (result != SUCCESS)
		return (free(animation), NULL);
	animation->frames_count = frames_count;
	animation->delay = delay;
	animation->loop = loop;
	return (animation);
}
