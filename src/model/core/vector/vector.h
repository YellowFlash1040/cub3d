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
void	destroy_vector(t_vector **vector_ref);

#endif
