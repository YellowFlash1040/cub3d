/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:29:33 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/15 15:34:22 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WALL_H
# define WALL_H

# include <stdlib.h>
# include "ft_string.h"
# include "direction.h"

# define WALL_INIT_ERR 1

typedef struct wall
{
	int			width;
	int			height;
	t_direction	direction;
	t_string	texture_path;
}	t_wall;

t_wall	*init_wall(void);
void	destroy_wall(t_wall **wall_ref);

#endif
