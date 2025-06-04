/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:41:43 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/15 15:52:30 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <stdlib.h>

# define COLOR_INIT_ERR 1

typedef unsigned char	t_channel;

typedef struct color
{
	t_channel	red;
	t_channel	green;
	t_channel	blue;
}	t_color;

t_color	*init_color(void);
void	destroy_color(t_color **color_ref);

#endif
