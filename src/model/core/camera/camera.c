#include "camera/camera.h"

t_camera	*init_camera(void)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	if (!camera)
		return (NULL);
	camera->rays = NULL;
	return (camera);
}

void	destroy_camera(t_camera **camera_ref)
{
	t_camera	*camera;

	if (!camera_ref || !*camera_ref)
		return ;
	camera = *camera_ref;
	free(camera);
	*camera_ref = NULL;
}
