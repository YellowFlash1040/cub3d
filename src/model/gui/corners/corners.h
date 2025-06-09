/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corners.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:29:49 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/06 15:56:49 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORNERS_H
# define CORNERS_H

# include <stdlib.h>
# include "map_point.h"

# define CORNERS_INIT_ERR 1

typedef struct corners
{
	t_map_point	top_left;
	t_map_point	bottom_right;
}	t_corners;

t_corners	*init_corners(void);
void		destroy_corners(t_corners **corners_ref);

#endif
