#include "ray/ray.h"

t_ray	*init_ray(void)
{
	t_ray	*ray;

	ray = (t_ray *)malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
	return (ray);
}

void	destroy_ray(t_ray **ray_ref)
{
	t_ray	*ray;

	if (!ray_ref || !*ray_ref)
		return ;
	ray = *ray_ref;
	free(ray);
	*ray_ref = NULL;
}
