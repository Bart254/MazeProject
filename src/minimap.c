#include "../headers/src.h"
#include "../headers/map.h"
#include "../headers/player.h"
#include "../headers/angle.h"

/**
 * draw_minimap - draws the map layout of the maze
 * @renderer: sdl2 renderer
 * @map: map struct
 * @h: height of screen
 * @w: width of screen
 */
void draw_minimap(SDL_Renderer *renderer, int h, int w)
{
	int x, y;
	minimap_t mm;

	mm.scale = 0.3;
	mm.w  = w * mm.scale;
	mm.h = h * mm.scale;
	mm.size_x = mm.w / (double) map.w;
	mm.size_y = mm.h / (double) map.h;
	mm.x_off = (w -10) - mm.w;
	mm.y_off = (h - 10) - mm.h;
	set_color(renderer, DARK);
	SDL_Rect minimap = {mm.x_off, mm.y_off, mm.w, mm.h};
	SDL_RenderFillRect(renderer, &minimap);
	set_color(renderer, GREEN);
	for(y = 0; y < map.h; y++)
	{
		for(x = 0; x < map.w; x++)
		{
			minimap.x = mm.x_off + x * mm.size_x;
			minimap.y = mm.y_off + y * mm.size_y;
			minimap.w = mm.size_x;
			minimap.h = mm.size_y;
			if (map.pos[y][x])
				SDL_RenderFillRect(renderer, &minimap);
		}
	}
	draw_miniplayer(renderer, mm);
}

/**
 * draw_miniplayer - draws the player's line of sight
 * @renderer: renderer for window
 * @player: player struct
 */
void draw_miniplayer(SDL_Renderer *renderer, minimap_t mm)
{
	int size;
	double x_temp, y_temp, radian, a;

	a = player.aov;
	radian = angle_to_radian(a);
	size = 10;
	x_temp = size * cos(radian);
	y_temp = size * sin(radian);
	if ((is_right(a) && x_temp < 0) || (is_left(a) && x_temp > 0))
		x_temp = -x_temp;
	if ((is_up(a) &&  y_temp > 0) || (is_down(a) && y_temp < 0))
		y_temp = -y_temp;
	set_color(renderer, GREEN);
	SDL_RenderDrawLine(renderer, mm.x_off + player.pos_x * mm.size_x,
			   mm.y_off + player.pos_y * mm.size_y,
		           mm.x_off + (player.pos_x + x_temp) * mm.size_x,
			   mm.y_off + (player.pos_y + y_temp) * mm.size_y);
}
