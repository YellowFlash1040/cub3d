/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:41:43 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/31 16:19:17 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <stdlib.h>

typedef __uint8_t	t_channel;
typedef __uint32_t	t_color;

t_color	get_color(t_channel r, t_channel g, t_channel b, t_channel a);
t_color	darken_color(t_color color, double percentage);

#endif
