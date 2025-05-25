#ifndef CAMERA_H
# define CAMERA_H

# include <stdlib.h>
# include "ray.h"

# define CAMERA_INIT_ERR 1

typedef struct camera
{
	t_ray		*rays;
}	t_camera;

t_camera	*init_camera(void);
void	destroy_camera(t_camera **camera_ref);

#endif
