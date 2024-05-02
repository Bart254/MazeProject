#include "../headers/ray.h"
#include "../headers/player.h"
#include <math.h>

/**
 * calc_wall_params - calculates height, top and bottom of wall
 * @wall: pointer to wall structure
 * @ray: ray that hits the wall
 * @h: height of the projection screen
 */
void calc_wall_params(wall_t *wall, ray_t ray, int h)
{
	wall->h = ((1 / ray.dist_wall) * player.dist_to_plane);
	wall->top = floor(h / 2 - wall->h / 2);
	wall->bottom = floor(h / 2 + wall->h / 2);
	if (wall->bottom > h)
		wall->bottom = h - 1;
	if (wall->top < 0)
		wall->top = 0;
}

