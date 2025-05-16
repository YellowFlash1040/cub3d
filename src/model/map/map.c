/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:48:20 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/16 17:01:58 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	destroy_cells(t_string **cells_ref, int rows_count);

t_map	*init_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->width = 0;
	map->height = 0;
	map->cells = NULL;
	return (map);
}

void	destroy_map(t_map **map_ref)
{
	t_map	*map;

	if (!map_ref || !*map_ref)
		return ;
	map = *map_ref;
	if (map->cells)
		destroy_cells(&map->cells, map->height);
	free(map);
	*map_ref = NULL;
}

void	destroy_cells(t_string **cells_ref, int rows_count)
{
	t_string	*cells;
	int			i;

	if (!cells_ref || !*cells_ref)
		return ;
	cells = *cells_ref;
	i = -1;
	while (++i < rows_count)
		free(cells[i]);
	free(cells);
	*cells_ref = NULL;
}
