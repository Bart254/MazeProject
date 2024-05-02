#include <stdio.h>
#include <math.h>
#include "../headers/ray.h"
#include "../headers/angle.h"
#include "../headers/map.h"
#include "../headers/player.h"

/**
 * get_hor_wall_dist - gets the distance to the horizontal
 * @ray: pointer to ray
 * @wall: pointer to the wall
 *
 * Function gets the distance from the ray
 * to the horizontal wall intersection
 *
 */
void get_hor_wall_dist(ray_t *ray, wall_t *wall)
{
	int x, y;
	double radian;

	radian = angle_to_radian(ray->alpha);
	if (ray->alpha == 0 || ray->alpha == 180)
	{
		ray->dist_hg = FLT_MAX;
		return;
	}
	check_hor_angle(ray, wall);

	while (1)
	{
		x = wall->hg_x / 1;
		y = wall->hg;
		if (x >= map.w || x < 0 ||
		    y >= map.h || y < 0)
		{
			ray->dist_hg = FLT_MAX;
			return;
		}
		if (map.pos[y][x] != 0)
		{
			if (ray->alpha == 90 || ray->alpha == 270)
				ray->dist_hg = fabs(player.pos_y - wall->hg);
			else
				ray->dist_hg = fabs((wall->hg_x - player.pos_x) / cos(radian));
			break;
		}
		else
		{
			wall->hg += ray->step_y;
			wall->hg_x += ray->step_x;
		}
	}
}

/**
 * get_vert_wall_dist - gets the distance to the horizontal
 * @ray: pointer to ray
 * @wall: pointer to the wall
 *
 * Function gets the distance from the ray
 * to the vert wall intersection
 *
 */
void get_vert_wall_dist(ray_t *ray, wall_t *wall)
{
	int x, y;
	double radian;

	radian = angle_to_radian(ray->alpha);
	if (ray->alpha == 90 || ray->alpha == 270)
	{
		ray->dist_vg = FLT_MAX;
		return;
	}

	check_vert_angle(ray, wall);
	while (1)
	{
		x = wall->vg / 1;
		y = wall->vg_y / 1;
		if (x >= map.w || x < 0 ||
		    y >= map.h || y < 0)
		{
			ray->dist_vg = FLT_MAX;
			return;
		}
		if (map.pos[y][x] != 0)
		{
			if (ray->alpha == 0 || ray->alpha == 180)
				ray->dist_vg = fabs(player.pos_x - wall->vg);
			else
				ray->dist_vg = fabs((wall->vg_y - player.pos_y)
						    / sin(radian));
			break;
		}
		else
		{
			wall->vg += ray->step_x;
			wall->vg_y += ray->step_y;
		}
	}
}

/**
 * get_wall_dist - gets the pependicular distance of the ray from the wall
 * @ray: pointer to ray struct
 * @wall: pointer to wall struct
 *
 * Function gets the distance to wall and also updates whether
 * the horizontal side (0) is hit or the vertical side (1)
 *
 */
void get_wall_dist(ray_t *ray, wall_t *wall)
{
		if (ray->dist_hg < ray->dist_vg)
		{
			ray->dist_wall = fabs(ray->dist_hg * cos(ray->beta));
			wall->x = wall->hg_x;
			wall->y = wall->hg;
			wall->side = 0;
		}
		else
		{
			ray->dist_wall = fabs(ray->dist_vg * cos(ray->beta));
			wall->x = wall->vg;
			wall->y = wall->vg_y;
			wall->side = 1;
		}
}

/**
 * check_hor_angle - changes values orientation of ray based on the angle
 * @ray: ray struct pointer
 * @wall: wall struct pointer
 */
void check_hor_angle(ray_t *ray, wall_t *wall)
{
	double x_temp, radian, a;

	a = ray->alpha;
	radian = angle_to_radian(a);
	if (a > 180)
	{
		ray->step_y = 1;
		wall->hg = floor(player.pos_y / 1) + 1;
		x_temp = (wall->hg - player.pos_y) / tan(radian);
		if ((is_left(a) && x_temp > 0) ||
		    (is_right(a) && x_temp < 0))
			x_temp = -x_temp;
		wall->hg_x = player.pos_x + x_temp;
	}
	else
	{
		ray->step_y = -1;
		wall->hg = floor(player.pos_y / 1) * 1;
		x_temp = (wall->hg - player.pos_y) / tan(radian);
		if ((is_left(a) && x_temp > 0) ||
		    (is_right(a)  && x_temp < 0))
			x_temp = -x_temp;
		wall->hg_x = player.pos_x + x_temp;
		(wall->hg)--;
	}

	if (a == 90 || a == 270)
	{
		wall->hg_x = player.pos_x;
		ray->step_x = 0;
	}
	else
	{
		ray->step_x = 1 / tan(radian);
		if ((is_right(a) && ray->step_x < 0) ||
		    (is_left(a) && ray->step_x > 0))
			ray->step_x = -(ray->step_x);
	}
}

/**
 * check_vert_angle - initializes vertical ray values
 * @ray: ray struct pointer
 * @wall: wall struct pointer
 */
void check_vert_angle(ray_t *ray, wall_t *wall)
{
	double radian, y_temp, a;

	a = ray->alpha;
	radian = angle_to_radian(a);
	if (is_right(a))
	{
		ray->step_x = 1;
		wall->vg = floor(player.pos_x / 1) + 1;
		y_temp = (wall->vg - player.pos_x) * tan(radian);
		if ((is_down(a) && y_temp < 0) ||
		     (is_up(a) && y_temp > 0))
			y_temp = -y_temp;
		wall->vg_y = player.pos_y + y_temp;
	}
	else
	{
		ray->step_x = -1;
		wall->vg = floor(player.pos_x / 1);
		y_temp = (wall->vg - player.pos_x) * tan(radian);
		if ((is_up(a) && y_temp > 0) ||
		    (is_down(a) && y_temp < 0))
			y_temp = -y_temp;
		wall->vg_y = player.pos_y + y_temp;
		(wall->vg)--;
	}

	if (a == 180 || a == 0)
	{
		wall->vg_y = player.pos_y;
		ray->step_y = 0;
	}
	else
	{
		ray->step_y = 1 * tan(radian);
		if ((ray->step_y > 0 && is_up(a)) ||
		    (ray->step_y < 0 && is_down(a)))
			ray->step_y = -(ray->step_y);
	}
}
