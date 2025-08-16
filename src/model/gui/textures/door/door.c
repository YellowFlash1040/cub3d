/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:30:19 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/21 13:44:52 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "door.h"

t_door	*init_door(void)
{
	t_door	*door;

	door = (t_door *)malloc(sizeof(t_door));
	if (!door)
		return (NULL);
	door->texture = NULL;
	return (door);
}

void	destroy_door(t_door **door_ref)
{
	t_door	*door;

	if (!door_ref || !*door_ref)
		return ;
	door = *door_ref;
	free(door);
	*door_ref = NULL;
}
