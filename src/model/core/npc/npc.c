/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:55:15 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/11 14:43:26 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npc.h"

t_npc	*init_npc(void)
{
	t_npc	*npc;

	npc = (t_npc *)malloc(sizeof(t_npc));
	if (!npc)
		return (NULL);
	npc->x = 0;
	npc->y = 0;
	npc->z = 0;
	return (npc);
}

void	destroy_npc(t_npc **npc_ref)
{
	t_npc	*npc;

	if (!npc_ref || !*npc_ref)
		return ;
	npc = *npc_ref;
	free(npc);
	*npc_ref = NULL;
}
