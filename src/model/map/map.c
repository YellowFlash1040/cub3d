/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:48:20 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/15 15:48:23 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	return (map);
}

void	destroy_map(t_map **map_ref)
{
	t_map	*map;

	if (!map_ref || !*map_ref)
		return ;
	map = *map_ref;
	free(map);
	*map_ref = NULL;
}
