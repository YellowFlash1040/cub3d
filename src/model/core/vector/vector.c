#include "vector/vector.h"

t_vector	*init_vector(void)
{
	t_vector	*vector;

	vector = (t_vector *)malloc(sizeof(t_vector));
	if (!vector)
		return (NULL);
	return (vector);
}

void	destroy_vector(t_vector **vector_ref)
{
	t_vector	*vector;

	if (!vector_ref || !*vector_ref)
		return ;
	vector = *vector_ref;
	free(vector);
	*vector_ref = NULL;
}
