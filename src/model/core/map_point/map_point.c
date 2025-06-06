/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:56:28 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/06 16:05:20 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_point.h"

t_map_point	*init_map_point(void)
{
	t_map_point	*map_point;

	map_point = (t_map_point *)malloc(sizeof(t_map_point));
	if (!map_point)
		return (NULL);
	map_point->x = 0;
	map_point->y = 0;
	return (map_point);
}

void	destroy_map_point(t_map_point **map_point_ref)
{
	t_map_point	*map_point;

	if (!map_point_ref || !*map_point_ref)
		return ;
	map_point = *map_point_ref;
	free(map_point);
	*map_point_ref = NULL;
}
