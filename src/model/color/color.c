/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:41:44 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/15 15:41:45 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	*init_color(void)
{
	t_color	*color;

	color = (t_color *)malloc(sizeof(t_color));
	if (!color)
		return (NULL);
	color->red = 0;
	color->green = 0;
	color->blue = 0;
	return (color);
}

void	destroy_color(t_color **color_ref)
{
	t_color	*color;

	if (!color_ref || !*color_ref)
		return ;
	color = *color_ref;
	free(color);
	*color_ref = NULL;
}
