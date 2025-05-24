/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:53:12 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/24 19:53:13 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdlib.h>

# define VECTOR_INIT_ERR 1

typedef struct vector
{
	double	x;
	double	y;
}	t_vector;

t_vector	*init_vector(void);
void		destroy_vector(t_vector **vector_ref);

#endif
