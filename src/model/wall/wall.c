/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:29:35 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/15 15:35:09 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wall.h"

t_wall	*init_wall(void)
{
	t_wall	*wall;

	wall = (t_wall *)malloc(sizeof(t_wall));
	if (!wall)
		return (NULL);
	wall->width = 0;
	wall->height = 0;
	wall->texture_path = NULL;
	wall->direction = DIRECTION_NONE;
	return (wall);
}

void	destroy_wall(t_wall **wall_ref)
{
	t_wall	*wall;

	if (!wall_ref || !*wall_ref)
		return ;
	wall = *wall_ref;
	if (wall->texture_path)
		destroy_string(wall->texture_path);
	free(wall);
	*wall_ref = NULL;
}
