#include <SDL2/SDL.h>

/**
 * set_color - sets the colour of the renderer
 * @renderer: sdl renderer to be set
 * @color: color to be set on the renderer
 */
void set_color(SDL_Renderer *renderer, SDL_Color color)
{
	SDL_SetRenderDrawColor(renderer, color.r,
				 color.g, color.b,
				 color.a);
}
