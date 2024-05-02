#ifndef RAY_H
#define RAY_H
#include <SDL2/SDL.h>
#include "src.h"

/**
 * ray_t - a ray structure
 * @alpha: angle of ray
 * @beta: difference between ray angle and player's angle of view
 * @dist_wall: distance of the ray from the wall
 * @dist_vg: distance of the ray from vertical wall
 * @dist_hg: distance of the ray from horizontal wall
 * @step_x: distance to next x-intersection
 * @step_y: distance to next y-intersection
 */
typedef struct ray_t {
	double alpha;
	double beta;
	double dist_wall;
	double dist_vg;
	double dist_hg;
	double step_x;
	double step_y;
} ray_t;

/**
 * wall_t - defines a wall structure
 * @x: x-coordinate of wall
 * @y: y coordinate of wall
 * @hg: horizontal grid of the wall
 * @hg_x: x-intersection of hg
 * @vg: vertical grid of the wall
 * @vg_y: y-intersection of vertical grid
 * @side: side of the wall that is hit, o if horizontal, 1 if certical
 * @h: height of wall
 * @top: top of wall
 * @bottom: bottom of wall
 */
typedef struct wall_t {
	int x;
	int y;
	int hg;
	double hg_x;
	int vg;
	double vg_y;
	int side;
	int h;
	int top;
	int bottom;
} wall_t;

void get_hor_wall_dist(ray_t *ray, wall_t *wall);
void get_vert_wall_dist(ray_t *ray, wall_t *wall);
void check_hor_angle(ray_t *ray, wall_t *wall);
void check_vert_angle(ray_t *ray, wall_t *wall);
void get_wall_dist(ray_t *ray, wall_t *wall);
void calc_wall_params(wall_t*, ray_t, int);
void draw_untextured_wall(int, wall_t wall, SDL_Renderer*);
void draw_textured_wall(SDL_Instance instance, wall_t wall, int col);

#endif /*RAY_H*/
