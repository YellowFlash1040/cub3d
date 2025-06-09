/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_point.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:56:26 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/06 15:56:27 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_POINT_H
# define MAP_POINT_H

# include <stdlib.h>

# define MAP_POINT_INIT_ERR 1

typedef struct map_point
{
	int	x;
	int	y;
}	t_map_point;

t_map_point	*init_map_point(void);
void		destroy_map_point(t_map_point **map_point_ref);

#endif
