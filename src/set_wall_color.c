#include "../headers/src.h"
#include "../headers/map.h"

/**
 * horizontal_color - sets the color of walls
 * @renderer: SDL2 renderer
 * @x: x-coordinate of wall
 * @y: y-coordinate of wall
 * @side: side of the wall, 0 if horizontal, otherwise 1
 */
void set_wall_color(SDL_Renderer *renderer, int x, int y, int side)
{
	if (side == 1)
		set_horizontal_color(renderer, x, y);
	else
		set_vertical_color(renderer, x, y);

}

/**
 * set_horizontal_color - sets the color of horizontal walls
 * @instance: SDL instance struct
 * @x: x-coordinate of wall
 * @y: y-coordinate of wall
 */
void set_horizontal_color(SDL_Renderer *renderer, int x, int y)
{
	switch (map.pos[y][x])
	{
		case 1:
			set_color(renderer, PURPLE);
	      		break;
    		case 2:
			set_color(renderer, GREEN);
			break;

		case 3:
			set_color(renderer, WHITE);
			break;
		case 4:
			set_color(renderer, WHITE);
	      		break;
              
    		default:
			set_color(renderer, GREEN);
			break;

	}
}

/**
 * set_vertical_color - sets the color of vertical walls
 * @renderer: SDL renderer
 * @map: 2D map
 * @x: x-coordinate of wall
 * @y: y-coordinate of wall
 */
void set_vertical_color(SDL_Renderer *renderer, int x, int y)
{
	switch (map.pos[y][x])
	{
		case 1:
			set_color(renderer, V_PURPLE);
	      		break;
    		case 2:
			set_color(renderer, V_GREEN);
			break;

		case 3:
			set_color(renderer, V_DARK);
			break;
		case 4:
			set_color(renderer, V_WHITE);
	      		break;
              
    		default:
			set_color(renderer, V_GREEN);
			break;

	}
}
