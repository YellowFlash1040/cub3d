/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npc_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:41:59 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/13 10:19:02 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "converter.h"

static void	copy_data(t_data *data, t_npc *npcs);

t_npc	*get_npcs(t_data *data)
{
	t_npc	*npcs;

	npcs = (t_npc *)malloc(sizeof(t_npc) * (data->sprites_count));
	if (!npcs)
		return (NULL);
	copy_data(data, npcs);
	return (npcs);
}

static void	copy_data(t_data *data, t_npc *npcs)
{
	int	i;

	i = -1;
	while (++i < data->sprites_count)
	{
		npcs[i].x = data->sprites[i].x * CELL_SIZE + CELL_SIZE / 2;
		npcs[i].y = data->sprites[i].y * CELL_SIZE + CELL_SIZE / 2;
		npcs[i].z = 20;
	}
}
