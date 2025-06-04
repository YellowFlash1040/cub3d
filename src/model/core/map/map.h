/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:48:18 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/04 16:53:54 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdlib.h>
# include "ft_string.h"

# define MAP_INIT_ERR 1

# define EMPTY_SPACE '0'
# define WALL '1'
# define CLOSED_DOOR '2'
# define OPENED_DOOR '3'

typedef struct map
{
	int			width;
	int			height;
	t_string	*cells;
}	t_map;

t_map	*init_map(void);
void	destroy_map(t_map **map_ref);
void	destroy_cells(t_string **cells_ref, int rows_count);
bool	is_obstacle(t_map *map, int x, int y);
bool	is_door(t_map *map, int x, int y);
void	toggle_door(t_map *map, int x, int y);

#endif
