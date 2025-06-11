/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:19:33 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/11 11:47:30 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_H
# define ANIMATION_H

# include <stdlib.h>
# include "ft_memory.h"
# include "frame.h"

# define ANIMATION_INIT_ERR 1

# define FRAMES_COUNT 16
# define ANIMATION_DELAY 0.1

typedef struct animation
{
	t_frame		**frames;
	int			frames_count;
	int			current;
	double		last_time;
	double		delay;
	bool		loop;
	bool		done;
}	t_animation;

t_animation	*init_animation(void);
int			build_animation(t_animation **animation_ref, int frames_count);
t_animation	*create_animation(int frames_count, double delay, bool loop);
void		destroy_animation(t_animation **animation_ref);
void		destroy_frames(t_frame ***frames_ref);

#endif
