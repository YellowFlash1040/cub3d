/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:33:47 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/15 15:49:18 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIRECTION_H
# define DIRECTION_H

typedef enum e_direction
{
	DIRECTION_NONE = 0,
	NORTH = 1,
	SOUTH = 2,
	WEST = 3,
	EAST = 4,
	UP = 1,
	DOWN = 2,
	LEFT = 3,
	RIGHT = 4
}	t_direction;

#endif
