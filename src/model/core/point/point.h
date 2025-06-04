/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:48:13 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/15 15:52:48 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include <stdlib.h>

# define POINT_INIT_ERR 1

typedef struct point
{
	int	x;
	int	y;
}	t_point;

t_point	*init_point(void);
void	destroy_point(t_point **point_ref);

#endif
