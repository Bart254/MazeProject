#include <stdio.h>
#include "../headers/src.h"
#include "../headers/ray.h"
#include "../headers/angle.h"
#include "../headers/player.h"
/**
 * draw_maze - draws the game on the screen
 * @screen: screen struct
 * @instance: sdl2 instance
 */
void draw_maze(screen_t screen, SDL_Instance instance)
{
	int x;
	double angle_btwn_rays;
	wall_t wall;
	ray_t ray;

	ray.alpha = player.aov - (player.fov / 2);
	angle_btwn_rays = player.fov / screen.w;
	if (ray.alpha < 0)
		ray.alpha += 360;
	for (x = screen.w - 1; x >= 0; x--)
	{
		ray.beta = angle_to_radian(fabs(player.aov - ray.alpha));
		get_hor_wall_dist(&ray, &wall);
		get_vert_wall_dist(&ray, &wall);
		get_wall_dist(&ray, &wall);
		calc_wall_params(&wall, ray, screen.h);

		/* draw the wall */
		set_wall_color(instance.renderer, wall.x, wall.y, wall.side);
		/*draw_untextured_wall(x, ray, wall, instance.renderer);*/
		draw_textured_wall(instance, wall, x);
		/*draw_floor(x, dist_wall, alpha, beta);*/
		/*draw_ceil(x, dist_wall, alpha, beta);*/
		ray.alpha += angle_btwn_rays;
		if (ray.alpha > 360)
			ray.alpha = ray.alpha - 360;
	}
}
