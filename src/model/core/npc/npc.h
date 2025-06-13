/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:55:13 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/11 14:00:22 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NPC_H
# define NPC_H

# include <stdlib.h>

# define NPC_INIT_ERR 1

typedef struct npc
{
	double	x;
	double	y;
	double	z;
}	t_npc;

t_npc	*init_npc(void);
void	destroy_npc(t_npc **npc_ref);

#endif
