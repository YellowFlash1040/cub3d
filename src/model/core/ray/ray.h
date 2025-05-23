#ifndef RAY_H
# define RAY_H

# include <stdlib.h>
# include "fpoint.h"

# define RAY_INIT_ERR 1

typedef struct ray
{
	t_fpoint	position;
	double		angle;
	double		x_offset;
	double		y_offset;
}	t_ray;

t_ray	*init_ray(void);
void	destroy_ray(t_ray **ray_ref);

#endif
