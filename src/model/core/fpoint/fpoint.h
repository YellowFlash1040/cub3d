/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpoint.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:52:57 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/24 19:52:58 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FPOINT_H
# define FPOINT_H

# include <stdlib.h>

# define FPOINT_INIT_ERR 1

typedef struct fpoint
{
	double	x;
	double	y;
}	t_fpoint;

t_fpoint	*init_fpoint(void);
void		destroy_fpoint(t_fpoint **point_ref);

#endif
