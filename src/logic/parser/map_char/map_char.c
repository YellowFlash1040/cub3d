/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:01:40 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/15 16:04:38 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_char.h"

bool	is_map_char(char c)
{
	if (c == '0')
		return (true);
	if (c == '1')
		return (true);
	if (c == 'N')
		return (true);
	if (c == 'S')
		return (true);
	if (c == 'E')
		return (true);
	if (c == 'W')
		return (true);
	return (false);
}
