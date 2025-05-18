#include "fpoint.h"

t_fpoint	*init_fpoint(void)
{
	t_fpoint	*point;

	point = (t_fpoint *)malloc(sizeof(t_fpoint));
	if (!point)
		return (NULL);
	point->x = 0;
	point->y = 0;
	return (point);
}

void	destroy_fpoint(t_fpoint **point_ref)
{
	t_fpoint	*point;

	if (!point_ref || !*point_ref)
		return ;
	point = *point_ref;
	free(point);
	*point_ref = NULL;
}
