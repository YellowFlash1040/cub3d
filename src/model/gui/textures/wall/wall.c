/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:29:35 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/11 13:39:04 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wall.h"

t_wall	*init_wall(void)
{
	t_wall	*wall;

	wall = (t_wall *)malloc(sizeof(t_wall));
	if (!wall)
		return (NULL);
	wall->texture = NULL;
	return (wall);
}

void	destroy_wall(t_wall **wall_ref)
{
	t_wall	*wall;

	if (!wall_ref || !*wall_ref)
		return ;
	wall = *wall_ref;
	if (wall->texture)
		mlx_delete_texture(wall->texture);
	free(wall);
	*wall_ref = NULL;
}
