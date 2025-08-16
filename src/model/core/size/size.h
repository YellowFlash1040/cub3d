/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:45:14 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/17 16:46:16 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIZE_H
# define SIZE_H

# include <stdlib.h>

# define SIZE_INIT_ERR 1

typedef struct size
{
	int	width;
	int	height;
}	t_size;

t_size	*init_size(void);
void	destroy_size(t_size **size_ref);

#endif
