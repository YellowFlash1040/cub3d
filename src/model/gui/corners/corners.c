/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corners.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:29:48 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/06 15:57:12 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corners.h"

t_corners	*init_corners(void)
{
	t_corners	*corners;

	corners = (t_corners *)malloc(sizeof(t_corners));
	if (!corners)
		return (NULL);
	corners->top_left = (t_map_point){0};
	corners->bottom_right = (t_map_point){0};
	return (corners);
}

void	destroy_corners(t_corners **corners_ref)
{
	t_corners	*corners;

	if (!corners_ref || !*corners_ref)
		return ;
	corners = *corners_ref;
	free(corners);
	*corners_ref = NULL;
}
