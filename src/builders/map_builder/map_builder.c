/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:56:33 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/16 15:05:06 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_builder.h"

int	build_map(t_map *map, int width, int height)
{
	int	i;

	map->width = width;
	map->height = height;
	map->cells = (t_string *)malloc(sizeof(t_string) * (map->height + 1));
	if (!map->cells)
		return (MALLOC_FAIL_ERR);
	i = -1;
	while (++i < map->height)
	{
		map->cells[i] = (char *)malloc(sizeof(char) * (map->width + 1));
		if (!map->cells[i])
			return (destroy_cells(&map->cells, i), MALLOC_FAIL_ERR);
		ft_bzero(map->cells[i], map->width + 1);
	}
	map->cells[i] = NULL;
	return (SUCCESS);
}
