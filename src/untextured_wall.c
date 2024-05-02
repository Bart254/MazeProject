#include <stdio.h>
#include "../headers/ray.h"
#include "../headers/src.h"
#include "../headers/map.h"

/**
 * draw_untextured_wall - draws untextured wall
 * @col: x-coordinate on the screen
 * @wall: wall of the maze that is hit
 * @renderer: sdl2 instancea renderer
 */
void draw_untextured_wall(int col, wall_t wall,
		          SDL_Renderer *renderer)
{
	SDL_RenderDrawLine(renderer, col, wall.top,
			    col, wall.bottom);
}

/**
 * draw_textured_wall - draws a textured wall
 * @instance: SDL_Instance struct
 * @wall: wall struct
 * @col: the vertical strip on the screen
 */
void draw_textured_wall(SDL_Instance instance, wall_t wall, int col)
{
	int i, text_w, text_h;
	SDL_Rect src, dest;

	switch (map.pos[wall.y][wall.x])
	{
		case 1:
			i = 0;
			break;
		case 2:
			i = 1;
			break;
		case 3:
			i = 2;
			break;
		case 4:
			i = 3;
			break;
		default:
			i = 0;
			break;	
	}

	//load_texture();
	SDL_QueryTexture(instance.texture[i], NULL, NULL, &text_w, &text_h);
	dest.x = col;
	dest.y = wall.top;
	dest.w = 1;
	dest.h = wall.h;
	if (wall.side == 0)
		src.x = (wall.hg_x - ((int)wall.hg_x)) * text_w;
	else
		src.x = (wall.vg_y - ((int)wall.vg_y)) * text_w;
	src.y = 0;
	src.w = 1;
	src.h = text_h;
	SDL_RenderCopy(instance.renderer, instance.texture[i], &src, &dest);
}

/*
 * draw_floor - draws the floor of the map
 * @x: the vertical strip
 * @factor: tile size
 * @dist: distance from player to the wall
 *
void draw_floor(int col, double perpdist, double alpha, double beta)
{
	int y, end, wall_height, text_w, text_h;
	double straight_dist_to_floor, floor_dist, x_temp, y_temp, map_x, map_y;
	SDL_Rect src, dest;

	SDL_QueryTexture(instance.floorTexture, NULL, NULL, &text_w, &text_h);
	wall_height = ((1 / perpdist) * player.dist_to_plane);
	end = SCREEN_HEIGHT / 2 + wall_height / 2;
	if (end > SCREEN_HEIGHT)
		end = SCREEN_HEIGHT - 1;
	for (y = end; y < SCREEN_HEIGHT; y++)
	{
		straight_dist_to_floor = player.dist_to_plane * ((double)player.h / (y - SCREEN_HEIGHT / 2));
		floor_dist = straight_dist_to_floor / cos(beta);
		x_temp = floor_dist * cos(angle_to_radian(alpha));
		y_temp = floor_dist * sin(angle_to_radian(alpha));
		if (((alpha < 90 || alpha > 270) && x_temp < 0) ||
		     ((alpha > 90 && alpha < 270) && x_temp > 0))
			x_temp = -x_temp;
		if ((alpha > 180 && y_temp < 0) || (alpha < 180 && y_temp > 0))
			y_temp = -y_temp;
		map_x = player.pos_x + x_temp;
		map_y = player.pos_y + y_temp;
		src.x = (map_x - (int)map_x) * text_w;
		src.y = (map_y - (int)map_y) * text_h;
		src.w = 1;
		src.h = 1;
		dest.x = col;
		dest.y = y;
		dest.w = 1;
		dest.h = 1;
		SDL_RenderCopy(instance.renderer, instance.floorTexture, &src, &dest);
	}

}


void draw_ceil(int col, double perpdist, double alpha, double beta)
{
	int y, start, wall_height, text_w, text_h;
	double straight_dist_to_ceil, ceil_dist, x_temp, y_temp, map_x, map_y;
	SDL_Rect src, dest;

	//load_texture();
	SDL_QueryTexture(instance.ceilTexture, NULL, NULL, &text_w, &text_h);
	SDL_QueryTexture(instance.texture, NULL, NULL, &text_w, &text_h);
	wall_height = ((1 / perpdist) * player.dist_to_plane);
	start = SCREEN_HEIGHT / 2 - wall_height / 2;
	if (start < 0)
		start = 0;
	for (y = start; y >= 0; y--)
	{
		straight_dist_to_ceil = player.dist_to_plane * ((double)player.h / (SCREEN_HEIGHT / 2 - y));
		ceil_dist = straight_dist_to_ceil / cos(beta);
		x_temp = ceil_dist * cos(angle_to_radian(alpha));
		y_temp = ceil_dist * sin(angle_to_radian(alpha));
		if (((alpha < 90 || alpha > 270) && x_temp < 0) ||
		     ((alpha > 90 && alpha < 270) && x_temp > 0))
			x_temp = -x_temp;
		if ((alpha > 180 && y_temp < 0) || (alpha < 180 && y_temp > 0))
			y_temp = -y_temp;
		map_x = player.pos_x + x_temp;
		map_y = player.pos_y + y_temp;
		src.x = (map_x - (int)map_x) * text_w;
		src.y = (map_y - (int)map_y) * text_h;
		src.w = 1;
		src.h = 1;
		dest.x = col;
		dest.y = y;
		dest.w = 1;
		dest.h = 1;
		SDL_RenderCopy(instance.renderer, instance.ceilTexture, &src, &dest);
	}

}
*/
