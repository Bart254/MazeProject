#include "../headers/src.h"
#include "../headers/player.h"
#include "../headers/map.h"

/**
 * main - Entry point into my 3D game
 * Return: Always 0
 */
int main(void)
{
	SDL_Instance instance;
	screen_t screen;
	bool keys[5] = {false, false, false, false, false};

	screen.w = 800;
	screen.h = 600;
	if (init_instance(&instance, screen) || get_map())
		exit(1);
	create_player(screen.w);

	/* start game loop */
	while (true)
	{
		SDL_Event event;

		if (poll_events(event, keys) == 1)
			break;
		set_color(instance.renderer, DARK);
		SDL_RenderClear(instance.renderer);
		draw_maze(screen, instance);
		check_keys(keys, instance.renderer, screen);
		SDL_RenderPresent(instance.renderer);
	}
	return (0);
}
