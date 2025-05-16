/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:48:18 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/16 16:56:46 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdlib.h>
# include "ft_string.h"

# define MAP_INIT_ERR 1

typedef struct map
{
	int			width;
	int			height;
	t_string	*cells;
}	t_map;

t_map	*init_map(void);
void	destroy_map(t_map **map_ref);
void	destroy_cells(t_string **cells_ref, int rows_count);

#endif
