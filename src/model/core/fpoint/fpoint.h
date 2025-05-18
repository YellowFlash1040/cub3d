#ifndef FPOINT_H
# define FPOINT_H

# include <stdlib.h>

# define FPOINT_INIT_ERR 1

typedef struct fpoint
{
	float x;
	float y;
}	t_fpoint;

t_fpoint	*init_fpoint(void);
void	destroy_fpoint(t_fpoint **point_ref);

#endif
