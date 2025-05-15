/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:48:15 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/15 15:48:17 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"

t_point	*init_point(void)
{
	t_point	*point;

	point = (t_point *)malloc(sizeof(t_point));
	if (!point)
		return (NULL);
	return (point);
}

void	destroy_point(t_point **point_ref)
{
	t_point	*point;

	if (!point_ref || !*point_ref)
		return ;
	point = *point_ref;
	free(point);
	*point_ref = NULL;
}
