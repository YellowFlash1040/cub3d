/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:48:20 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/10 17:01:50 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

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

int	build_map(t_map *map, int width, int height)
{
	int	i;

	if (!map)
		return (EMPTY_PTR_ERR);
	if (width <= 0 || height <= 0)
		return (INVALID_VALUE);
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
